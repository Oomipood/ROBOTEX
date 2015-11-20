//=============================================================================================
//=============================================================================================
//=============================================================================================
//==============================FOLKRACE ROBI FINAL v1.0=======================================
//=============================================================================================
//=============================================================================================
//=============================================================================================
//===============================NEW PING Library==============================================
#include <NewPing.h>
//===============================All include files=============================================
#include "_config.h"
#include "_debug.h"
#include "_motors.h"
#include "_sensors.h"
#include "_tests.h"
#include "_logics.h"
//=============================================================================================
//===============================INITIALIZATION================================================
//=============================================================================================
void setup(){
#ifdef DEBUG
  Serial.begin(SERIAL_PORT_SPEED);
#endif

					DEBUG_PRINT("STARTING PROGRAM");
						for (byte i=0; i<=15; i++){
							DEBUG_PRINT(".");
							delay(100);
						}
					DEBUG_PRINTLN("OK!");
					DEBUG_PRINTLN("DEBAG MODE is ON!");
					DEBUG_PRINT("SERIAL SPEED is ");
					DEBUG_PRINTLN(SERIAL_PORT_SPEED);
					DEBUG_PRINTLN();

//==== Pin configuration ======================================================================				
  pinMode(LEFT_TRIGGER_PIN, OUTPUT);
  pinMode(CENTER_TRIGGER_PIN, OUTPUT);
  pinMode(RIGHT_TRIGGER_PIN, OUTPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);
  pinMode(CENTER_ECHO_PIN, INPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACK, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(SONARS_ERROR_LED, OUTPUT);

//===== Sonars Test at start ===================================================================

#ifdef DEBUG
	CYCLE_TIME = millis();
#endif

  while (sonarsTestAtStart == false) {

      sonarsTestAtStart = sonarsTest();

      if (sonarsTestAtStart == false){
			        DEBUG_PRINTLN("TROUBLE WITH SENSORS!");
			        //DEBUG_PRINTLN("");
			digitalWrite(SONARS_ERROR_LED, HIGH); //If some trouble with sonars, LED is on.
			sonars_test_fail_count++; //decrease sonars test counter
					DEBUG_PRINT("SONARS_TEST_FAIL_COUNT:");

						if (sonars_test_fail_count > 0){
						DEBUG_PRINTLN(sonars_test_fail_count);
						DEBUG_PRINTLN("");
						}

				if (sonars_test_fail_count >= SONARS_TEST_MAX_FAIL_COUNT)
					sonarsTestAtStart = true;

        } 
      //delay(SONARS_TEST_DELAY);
      }

      if (sonars_test_fail_count >= 1 ){
      	digitalWrite(SONARS_ERROR_LED, HIGH);
      				DEBUG_PRINTLN("SONARS TEST IS NOT PASSED! :((( ROBOT IS STARTING...");
      	}
      else {
      	digitalWrite(SONARS_ERROR_LED, LOW); //If sonars test is passed, LED is off.

					DEBUG_PRINTLN("SONARS TEST IS PASSED! :))) ROBOT IS STARTING...");
			}

DEBUG_PRINT("SONARS TEST TIME is ");			
DEBUG_PRINT(long(millis())-CYCLE_TIME);
DEBUG_PRINT("ms");
DEBUG_PRINTLN("");

//==== Start delay and other settings ============================================================
  delay(ROBOT_START_DELAY);
  
left_motor_forward(LEFT_MOTOR_MAX_SPEED/2);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED/2);


  //left_motor_forward(LEFT_MOTOR_MAX_SPEED/4);
  //right_motor_forward(RIGHT_MOTOR_MAX_SPEED/4);

  //left_motor_forward(LEFT_MOTOR_MAX_SPEED);
  //right_motor_forward(RIGHT_MOTOR_MAX_SPEED);

					//DEBUG_PRINT("Starting LEFT MOTOR with speed: ");
					//DEBUG_PRINTLN(LEFT_MOTOR_MAX_SPEED);
					//DEBUG_PRINT("Starting RIGHT MOTOR with speed: ");
					//DEBUG_PRINTLN(RIGHT_MOTOR_MAX_SPEED);
					//DEBUG_PRINTLN("GOING TO LOOP CYCLE...");
					//DEBUG_PRINTLN("");
DEBUG_PRINTLN("");

#ifdef DEBUG
  DEBUG_PRINT("TESTING MOTORS...");
  left_motor_forward(100);
  delay(1000);
  right_motor_forward(100);
  delay(1000);
  right_motor_stop();
  left_motor_stop();
  delay(2000);
  left_motor_back(100);
  delay(1000);
  right_motor_back(100);
  delay(1000);
  right_motor_stop();
  left_motor_stop();
  delay(1000);
  DEBUG_PRINTLN("OK!");

#endif

}

//===========================================================================================
//=====================================MAIN PROGRAM==========================================
//===========================================================================================
void loop(){

	#ifdef DEBUG
		CYCLE_TIME = 0;
		CYCLE_TIME = millis();
	#endif


	distLeft = left_sonar_scan();
	logics();
  	delay(TIME_BETWEEN_PINGS);
  
  	//DEBUG_DELAY(1000);

  	distCenter = center_sonar_scan();
  	logics();
  	delay(TIME_BETWEEN_PINGS);

  	//DEBUG_DELAY(1000);

  	distRight = right_sonar_scan();
  	logics();
  	delay(TIME_BETWEEN_PINGS);

#ifdef DEBUG
  					//SHOW 1 LOOP CYCLE TIME
  					DEBUG_PRINT("LOOP CYCLE TIME IS ");
  					DEBUG_PRINT(long(millis()-CYCLE_TIME));
  					DEBUG_PRINTLN("ms");

  					//SHOW SENSORS DATA
				  	DEBUG_PRINT("SONARS L: ");
				  	DEBUG_PRINT(distLeft);
				  	DEBUG_PRINT(" | C: ");
				  	DEBUG_PRINT(distCenter);
				  	DEBUG_PRINT(" | R: ");
				  	DEBUG_PRINTLN(distRight);

  DEBUG_DELAY(1000);
#endif
}
