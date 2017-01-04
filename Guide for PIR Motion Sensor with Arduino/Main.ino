int led= 13; //LED connected to pin 13 
int sensepin= 2; // Arduino Pin connected to OUT of PIR
int state=LOW; // Assuming No motion initally
int value= 0; // Variable which stores status of the sensor

void setup() // Executed once
{
    pinMode(led,OUTPUT); // LED as output
    pinMode(sensepin, INPUT); // Sensor as input
    Serial.begin(9600); // Baud Rate : Characters/sec. In this case, bits/sec
}

void loop()
{
    value= digitalRead(sensepin); // Read PIR value
    if( value == HIGH)
      {
         digitalWrite(led, HIGH); // Turn LED on
         delay(100); // Delay of 100 milliseconds
      
         if( state == LOW)
          {
            Serial.println("Motion!"); // Motion detected
            state = HIGH; // Flipping state to HIGH
          }
       }
     else
       {
          digitalWrite(led, LOW); // Turn LED off
          delay(250); // Delay of 250 milliseconds
          if( state == HIGH)
          {
            Serial.println("Motion Stopped");
            state= LOW; // State flipped back to LOW
          }
        }
}
