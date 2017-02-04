int sensor_pin = 6; // Pin for capacitive touch sensor

void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
}
 
void loop() 
{
  int value = digitalRead(sensor_pin);
  Serial.println(value);
  delay(500);
}
