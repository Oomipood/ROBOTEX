//=============================FUNCTION FOR CHECHING SONARS AT START===========================
boolean sonarsTest(){

  DEBUG_PRINTLN("Starting sonars test...");
  boolean testPassed = true;

      //Check the left sonar
      for (int i = 0; i <= SONARS_START_CHECK_COUNT; i++){

        distLeft = left_sonar_scan();
        delay(TIME_BETWEEN_PINGS);

        if (distLeft == 0 || distLeft > MAX_DISTANCE)
          distLeftErrorCounter++;

      }
      //Check center sonar
      for (int y = 0; y <= SONARS_START_CHECK_COUNT; y++){

        distCenter = center_sonar_scan();
        delay(TIME_BETWEEN_PINGS);

        if (distCenter == 0 || distCenter > MAX_DISTANCE)
          distCenterErrorCounter++;

      }
      //Check right sonar
      for (int y = 0; y <= SONARS_START_CHECK_COUNT; y++){

        distRight = right_sonar_scan();
        delay(TIME_BETWEEN_PINGS);

        if (distRight == 0 || distRight > MAX_DISTANCE)
          distRightErrorCounter++;

      }
    //Show the results:
    DEBUG_PRINT("Error counters is: L: ");
    DEBUG_PRINT(distLeftErrorCounter);
    DEBUG_PRINT(" | C: ");
    DEBUG_PRINT(distCenterErrorCounter);
    DEBUG_PRINT(" | R: ");
    DEBUG_PRINTLN(distRightErrorCounter);

    //What to do if some sensor is wrong
    if (distLeftErrorCounter > SONAR_MAX_ERROR_COUNT){
        DEBUG_PRINTLN("ERROR: LEFT SONAR IS WRONG!!!");
        digitalWrite(SONARS_ERROR_LED, HIGH);
        testPassed = false;
      }
    if (distCenterErrorCounter > SONAR_MAX_ERROR_COUNT){
        DEBUG_PRINTLN("ERROR: CENTER SONAR IS WRONG!!!");
        digitalWrite(SONARS_ERROR_LED, HIGH);
        testPassed = false;
      }
    if (distRightErrorCounter > SONAR_MAX_ERROR_COUNT){
        DEBUG_PRINTLN("ERROR: RIGHT SONAR IS WRONG!!!");
        digitalWrite(SONARS_ERROR_LED, HIGH);
        testPassed = false;
      }

  distLeftErrorCounter = 0;
  distCenterErrorCounter = 0;
  distRightErrorCounter = 0;

  return testPassed;
}