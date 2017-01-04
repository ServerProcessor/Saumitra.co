int dataq = 0;

void setup()
 {
    Serial.begin(9600); // Baud Rate : 9600 ( Bits / sec )
 }

void loop()
{
  if(Serial.available()>0) // Checks for the characters available in the receive buffer to read
   {
      dataq = Serial.read(); // Read the Data
      Serial.print("  ");
      Serial.print(dataq,DEC);
   }
}
