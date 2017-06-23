#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

int led1 = D0;
int led2 = D7;

void setup() 
{
    Serial.println("Blink Demo");
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop()
{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    Serial.println("High...");
    
    delay(1000);
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    Serial.println("Low...");
    
    delay(1000);
}


