//=========================MOTORS FUNCTIONS======================================================

void left_motor_forward(byte left_motor_speed){
  analogWrite(LEFT_MOTOR_FORWARD, left_motor_speed);
  digitalWrite(LEFT_MOTOR_BACK, 0);
}

void left_motor_back(byte left_motor_speed){
  analogWrite(LEFT_MOTOR_BACK, left_motor_speed);
  digitalWrite(LEFT_MOTOR_FORWARD, 0);
}

void right_motor_forward(byte right_motor_speed){
  analogWrite(RIGHT_MOTOR_FORWARD, right_motor_speed);
  digitalWrite(RIGHT_MOTOR_BACK, 0);
}

void right_motor_back(byte right_motor_speed){
  analogWrite(RIGHT_MOTOR_BACK, right_motor_speed);
  digitalWrite(RIGHT_MOTOR_FORWARD, 0);
}

void left_motor_stop(){
  digitalWrite(LEFT_MOTOR_FORWARD, 0);
  digitalWrite(LEFT_MOTOR_BACK, 0);
}

void right_motor_stop(){
  digitalWrite(RIGHT_MOTOR_FORWARD, 0);
  digitalWrite(RIGHT_MOTOR_BACK, 0);
}

void motors_forward_right(byte motors_speed){
  analogWrite(RIGHT_MOTOR_FORWARD, (RIGHT_MOTOR_TURN_K * motors_speed));
  analogWrite(LEFT_MOTOR_FORWARD, motors_speed);
  digitalWrite(RIGHT_MOTOR_BACK, 0);
  digitalWrite(LEFT_MOTOR_BACK, 0);
}

void motors_forward_left(byte motors_speed){
  analogWrite(RIGHT_MOTOR_FORWARD, motors_speed);
  analogWrite(LEFT_MOTOR_FORWARD, (LEFT_MOTOR_TURN_K * motors_speed));
  digitalWrite(RIGHT_MOTOR_BACK, 0);
  digitalWrite(LEFT_MOTOR_BACK, 0);
}