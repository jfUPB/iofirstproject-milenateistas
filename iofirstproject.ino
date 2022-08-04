void task1()
{
    enum class Task1States
    {
    INIT,
    WAIT_TIMEOUT
    };

    static Task1States task1State = Task1States::INIT;
    static uint8_t Lastbutton1Pin = LOW;
    static uint8_t Lastbutton2Pin = LOW;

    constexpr uint32_t INTERVAL = 1000;
    constexpr uint8_t button1Pin = 12;
    constexpr uint8_t button2Pin = 13;
    constexpr uint8_t ledRed = 14;
    constexpr uint8_t ledGreen = 25;
    constexpr uint8_t ledBlue = 26;
    constexpr uint8_t ledYellow = 27;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        pinMode(button1Pin, INPUT_PULLUP);
        pinMode(button2Pin, INPUT_PULLUP);
        pinMode(ledRed, OUTPUT);
        pinMode(ledGreen, OUTPUT);
        pinMode(ledBlue, OUTPUT);
        pinMode(ledYellow, OUTPUT);
        task1State = Task1States::WAIT_TIMEOUT;

        break;
    }
    case Task1States::WAIT_TIMEOUT:
    {
      uint8_t btn1State = digitalRead(button1Pin);
      uint8_t btn2State = digitalRead(button2Pin);


                // Actualizar las variables de los pulsadores 
        if((Lastbutton1Pin !=btn1State) || (Lastbutton2Pin !=btn2State))
        {
 if (btn1State == HIGH && btn2State == HIGH){
                     digitalWrite(ledRed, LOW);
                     digitalWrite(ledBlue, LOW);
                     digitalWrite(ledGreen, LOW);
                     digitalWrite(ledYellow, HIGH);
                     printf("Led Yellow on");
                     
                }

                if (btn1State == LOW && btn2State == LOW)
                {
                     digitalWrite(ledRed, HIGH);
                     digitalWrite(ledBlue, LOW);
                     digitalWrite(ledGreen, LOW);
                     digitalWrite(ledYellow, LOW);
                     printf("Led Red on");
                }
                
                if (btn2State == HIGH && btn1State == LOW)
                {
                     digitalWrite(ledRed, LOW);
                     digitalWrite(ledBlue, LOW);
                     digitalWrite(ledGreen, HIGH);
                     digitalWrite(ledYellow, LOW);
                     printf("Led Green on");
                }       
            
                if (btn1State == HIGH && btn2State == LOW)
                {
                     digitalWrite(ledRed, LOW);
                     digitalWrite(ledBlue, HIGH);
                     digitalWrite(ledGreen, LOW);
                     digitalWrite(ledYellow, LOW);
                     printf("Led Blue on");
                }

                Lastbutton1Pin = btn1State;
                Lastbutton2Pin = btn2State;
        break;
        }
    }
               

          default:
          {
            Serial.println("Error");
          }
     }
}

void setup()
{
	task1();
}

void loop()
{
	task1();
}
