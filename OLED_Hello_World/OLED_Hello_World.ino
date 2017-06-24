#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

#include "SeeedGrayOLED.h"

void setup()
{
    RGB.control(true);
    RGB.color(0, 0, 0);
    
    Wire.begin();
    
    SeeedGrayOled.init(SSD1327);      // initialize SEEED OLED display
    SeeedGrayOled.clearDisplay();     // Clear Display.
    SeeedGrayOled.setNormalDisplay(); // Set Normal Display Mode
    SeeedGrayOled.setVerticalMode();  // Set to vertical mode for displaying text 
}

void loop()
{
    char msg[32];
    static int count = 0;

    sprintf(msg, "Count = %d", count++);
    SeeedGrayOled.setTextXY(5,0);
    SeeedGrayOled.putString(msg);    
    delay(1000);
}

