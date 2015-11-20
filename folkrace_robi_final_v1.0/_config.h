//#define DEBUG  // Debug on/off
//MOTORS
#define LEFT_MOTOR_FORWARD 5
#define LEFT_MOTOR_BACK 6
#define RIGHT_MOTOR_FORWARD 10
#define RIGHT_MOTOR_BACK 11
#define LEFT_MOTOR_TURN_K 0.7
#define RIGHT_MOTOR_TURN_K 0.7
//SONARS
#define MAX_DISTANCE 500       // Maximum distance we want to ping for (in centimeters 400-500cm)
#define TIME_BETWEEN_PINGS 29 // Wait between pings. 29ms should be the shortest delay between pings.

#define LEFT_TRIGGER_PIN  4  //Left Ultrasonic sensor (III)
#define LEFT_ECHO_PIN     7
#define CENTER_TRIGGER_PIN  3  //Center Ultrasonic sensor (I)
#define CENTER_ECHO_PIN     8	
#define RIGHT_TRIGGER_PIN  2  //Right Ultrasonic sensor (II)
#define RIGHT_ECHO_PIN     9

#define SONARS_START_CHECK_COUNT 9 //sonar sensors check amount before start
#define SONAR_MAX_ERROR_COUNT 3   //Maximux errors for sensor
#define SONARS_ERROR_LED 13 	 //Error LED
#define SONARS_TEST_DELAY 2  //Time to retry sonars test
#define SONARS_TEST_MAX_FAIL_COUNT 5 //how many retrys do, if test is fail.

#define STOP_DISTANCE 4
#define WALL_DISTANCE 3

//START SETTINGS
#define ROBOT_START_DELAY 0
#define LEFT_MOTOR_MAX_SPEED 180 //norm 160
#define RIGHT_MOTOR_MAX_SPEED 180 //norm 160
#define SPEED0 0
#define SPEED1 0
#define SPEED2 0
#define SPEED3 20
#define SERIAL_PORT_SPEED 9600
//MOVING
#define MOVING_FORWARD_DELAY 5 //norm 5
#define TURNING_LEFT_DELAY 3 //norm 4
#define TURNING_RIGHT_DELAY 3 //norm 4

#define MIN_LEFT_DISTANCE 2
#define NORM_LEFT_DISTANCE 15
#define MIN_RIGHT_DISTANCE 2
#define NORM_RIGHT_DISTANCE 15
#define MIN_CENTER_DISTANCE 4
#define NORM_CENTER_DISTANCE 25

byte left_motor_speed;
byte right_motor_speed;
byte motors_speed = 150;

// Wall stick counters
byte counterWallLeft = 0;
byte counterWallCenter = 0;
byte counterWallRight = 0;

//Logics variables
unsigned int distLeft = 1;     //Left distance
unsigned int distCenter = 1;  //Center distance
unsigned int distRight = 1;  //Right distance
//Sonars Test
byte distLeftErrorCounter = 0;       //Left sonar error counter
byte distCenterErrorCounter = 0;    //Center sonar error counter
byte distRightErrorCounter = 0;    //right sonar error counter
boolean sonarsTestAtStart = false; //Test for start sonars check (false - start test, true - no test)
byte sonars_test_fail_count = 0; //Test fails

//Others
long CYCLE_TIME = 0; //For time measurement 