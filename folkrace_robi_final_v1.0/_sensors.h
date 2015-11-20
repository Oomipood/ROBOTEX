//=========================SCAN ULTRASONIC SONARS=============================================

unsigned int left_sonar_scan(){

  NewPing sonarLeft(LEFT_TRIGGER_PIN, LEFT_ECHO_PIN, MAX_DISTANCE);
  unsigned int resultLeft = sonarLeft.ping();
  resultLeft = resultLeft / US_ROUNDTRIP_CM;
    if (resultLeft == 0 || resultLeft == 1)
      return 2;
    else
    return resultLeft;

}
unsigned int center_sonar_scan(){

  NewPing sonarCenter(CENTER_TRIGGER_PIN, CENTER_ECHO_PIN, MAX_DISTANCE);
  unsigned int resultCenter = sonarCenter.ping();
  resultCenter = resultCenter / US_ROUNDTRIP_CM;
    if (resultCenter == 0 || resultCenter == 1)
      return 2;
    else
    return resultCenter;

}
unsigned int right_sonar_scan(){

  NewPing sonarRight(RIGHT_TRIGGER_PIN, RIGHT_ECHO_PIN, MAX_DISTANCE);
  unsigned int resultRight = sonarRight.ping();
  resultRight = resultRight / US_ROUNDTRIP_CM;
      if (resultRight == 0 || resultRight == 1)
        return 2;
      else
      return resultRight;
}