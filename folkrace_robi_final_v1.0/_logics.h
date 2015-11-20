void logics(){
//
//===============================  Check if distance is 0  =========================
  /*
  if (distLeft <= MIN_LEFT_DISTANCE){
    left_motor_stop();
    right_motor_stop();
  }
  if (distCenter <= MIN_CENTER_DISTANCE){
    left_motor_stop();
    right_motor_stop();
  }
  if (distRight <= MIN_RIGHT_DISTANCE){
    left_motor_stop();
    right_motor_stop();
  }
  */
//=================================  WALL STICK CHECK ===================
  if (distLeft <= MIN_LEFT_DISTANCE){
    counterWallLeft ++;}
    else {
      counterWallLeft = 0;
    }
  if (distCenter <= MIN_CENTER_DISTANCE){
    counterWallCenter ++;}
    else {
      counterWallCenter = 0;
    }
  if (distRight <= MIN_RIGHT_DISTANCE){
    counterWallRight ++;}
    else {
      counterWallRight = 0;
    }


 if (counterWallLeft == 2){
     counterWallLeft = 0;
      right_motor_stop();
      left_motor_stop(); 

      right_motor_back(RIGHT_MOTOR_MAX_SPEED);
      delay(25);  
 }
  if (counterWallCenter == 2){
     counterWallCenter = 0; 
     right_motor_stop();
     left_motor_stop();
     delay(10);
     right_motor_back(RIGHT_MOTOR_MAX_SPEED);
     left_motor_back(LEFT_MOTOR_MAX_SPEED);
     delay(200);
     right_motor_stop();
     left_motor_stop();
     delay(10);

         if (distRight > distLeft){
              right_motor_forward(RIGHT_MOTOR_MAX_SPEED/4);
              left_motor_forward(LEFT_MOTOR_MAX_SPEED/2);
              delay(50);
              right_motor_stop();
              left_motor_stop();
         }
         else {
              right_motor_forward(RIGHT_MOTOR_MAX_SPEED/2);
              left_motor_forward(LEFT_MOTOR_MAX_SPEED/4);
              delay(50);
              right_motor_stop();
              left_motor_stop();
           } 
 }
   if (counterWallRight == 2){
     counterWallCenter = 0; 
      right_motor_stop();
      left_motor_stop();
      delay(10);

      left_motor_back(LEFT_MOTOR_MAX_SPEED);
      delay(20); 
      right_motor_stop();
      left_motor_stop();  
 }

//================================  MOVING FORWARD/LEFT/RIGHT ==============
  if (distLeft <= distCenter & distRight <= distCenter){
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
delay(MOVING_FORWARD_DELAY);
}
    
  //Turn left if:
  else if (distLeft > distRight){
left_motor_forward(LEFT_MOTOR_MAX_SPEED/8);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
//left_motor_stop();
  delay(TURNING_LEFT_DELAY);
  }
    
  //Turn right if:
  else if (distLeft < distRight){
//right_motor_stop();
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED/8);
   delay(TURNING_RIGHT_DELAY);
 }

 else {
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
delay(MOVING_FORWARD_DELAY);
 }

// 
/*
//RESULT COUNTERS
  //byte left_result = 0;
  //byte center_result = 0;
  //byte right_result = 0;
  byte reslt[3] = {0,0,0};

//START CALCULATE RESULT
//===CENTER===============================
  if (distCenter >= NORM_CENTER_DISTANCE)
    reslt[1] = 0;
  else if (distCenter < NORM_CENTER_DISTANCE & distCenter > MIN_CENTER_DISTANCE)
    reslt[1] = 1;
  else
    reslt[1] = 2;
//===RIGHT================================
  if (distRight >= NORM_RIGHT_DISTANCE)
    reslt[2] = 0;
  else if (distRight < NORM_RIGHT_DISTANCE & distRight > MIN_RIGHT_DISTANCE)
    reslt[2] = 1;
  else
    reslt[2] = 2;
//===LEFT=================================
  if (distLeft >= NORM_LEFT_DISTANCE)
    reslt[0] = 0;
  else if (distLeft < NORM_LEFT_DISTANCE & distLeft > MIN_LEFT_DISTANCE)
    reslt[0] = 1;
  else
    reslt[0] = 2;
//END OF CALCULATING RESULT

DEBUG_PRINT("LOGIC RESULT IS L: ");
DEBUG_PRINT(reslt[0]);
DEBUG_PRINT(" | C: ");
DEBUG_PRINT(reslt[1]);
DEBUG_PRINT(" | R: ");
DEBUG_PRINT(reslt[2]);
DEBUG_PRINTLN("");

//MOVING MOTORS FORWARD
if (reslt[0] == 0 & reslt[1] == 0 & reslt[2] == 0) //{0.0.0}
{
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
DEBUG_PRINTLN("MOVING FORWARD");
}
//TURNING TO RIGHT
if (reslt[0] == 1)                                 //{1.0.0}
{
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(SPEED2);
DEBUG_PRINTLN("TURNING RIGHT with SPEED2");  
}
if (reslt[0] == 1 & reslt[1] == 1)                 //{1.1.0}
{
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(SPEED1);
DEBUG_PRINTLN("TURNING RIGHT with SPEED1");  
}
if (reslt[0] == 2)                                 //{2.0.0}
{
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(SPEED3);
DEBUG_PRINTLN("TURNING RIGHT with SPEED3");  
}
if (reslt[0] == 2 && reslt[1] == 1)                //{2.1.0}
{
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(SPEED0); 
DEBUG_PRINTLN("TURNING RIGHT with SPEED0"); 
}
if (reslt[0] == 2 && reslt[1] == 2)                //{2.2.0}
{
left_motor_forward(LEFT_MOTOR_MAX_SPEED);
right_motor_forward(SPEED0);
DEBUG_PRINTLN("TURNING RIGHT with SPEED0");  
}

//TURNING TO LEFT
if (reslt[2] == 1)                                 //{0.0.1}
{
left_motor_forward(SPEED2);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
DEBUG_PRINTLN("TURNING LEFT with SPEED2");  
}
if (reslt[1] == 1 & reslt[2] == 1)                 //{0.1.1}
{
left_motor_forward(SPEED1);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
DEBUG_PRINTLN("TURNING LEFT with SPEED1");  
}
if (reslt[2] == 2)                                 //{0.0.2}
{
left_motor_forward(SPEED3);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
DEBUG_PRINTLN("TURNING LEFT with SPEED3");  
}
if (reslt[1] == 1 && reslt[2] == 2)                //{0.1.2}
{
left_motor_forward(SPEED0);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
DEBUG_PRINTLN("TURNING LEFT with SPEED0");  
}
if (reslt[1] == 2 && reslt[2] == 2)                //{0.2.2}
{
left_motor_forward(SPEED0);
right_motor_forward(RIGHT_MOTOR_MAX_SPEED);
DEBUG_PRINTLN("TURNING LEFT with SPEED0");  
}

*/
}