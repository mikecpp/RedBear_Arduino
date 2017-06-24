//#include <Wire.h>
#include <application.h>
#include "rgb_lcd.h"

#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

void setup() 
{
    RGB.control(true);
    RGB.color(0, 0, 0);
    
    // set up the LCD's number of columns and rows:
    delay(3000);
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("hello, world!");

    delay(1000);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.clear();
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("Hello");

    delay(1000);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
