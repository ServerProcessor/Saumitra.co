int Dust_Analog = 0; // Arduin Pin A0
int Dust_Pin = 7;    

float Dust_Voltage = 0;
float C_Voltage = 0;
float Density_Dust = 0;
  
void setup()
{
  Serial.begin(9600); // Baud Rate
  pinMode(Dust_Pin,OUTPUT);
}
  
void loop()
{
  digitalWrite(Dust_Pin,LOW); // LED gets powered on
  delayMicroseconds(280); // The output value to be measured 0.28ms after the LED turns on ( given in datasheet )
  
  Dust_Voltage = analogRead(Dust_Analog); // Read the raw value
  
  delayMicroseconds(40);
  digitalWrite(Dust_Pin,HIGH); // LED gets turned off
  delayMicroseconds(9680);
  
  C_Voltage = Dust_Voltage * (5.0 / 1024.0);
  Density_Dust = 0.17 * C_Voltage - 0.1;
  
  Serial.print("Raw Signal Value : ");
  Serial.print(Dust_Voltage);
  
  Serial.print(" - Voltage: ");
  Serial.print(C_Voltage);
  
  Serial.print(" - Dust Density: ");
  Serial.println(Density_Dust); // mg/m3
  
  delay(1000);
}
