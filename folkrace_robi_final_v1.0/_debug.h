  #ifdef DEBUG
    
    #define DEBUG_PRINTLN(x)  Serial.println (x)
    #define DEBUG_PRINT(x)  Serial.print (x)
    #define DEBUG_DELAY(x)  delay (x)
  #else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINTLN(x)
    #define DEBUG_DELAY(x)

  #endif