int S0= 4; // S0 connected to Arduino pin 4
int S1= 5; // S1 connected to Arduino pin 5
int S2= 6; // S2 connected to Arduino pin 6 
int S3= 7; // S3 connected to Arduino pin 7
int senseout= 10; // Out connected to Arduino pin 10
int frequency=0;

void setup()
{
   pinMode(S0, OUTPUT);
   pinMode(S1, OUTPUT);
   pinMode(S2, OUTPUT);
   pinMode(S3, OUTPUT);
   pinMode(senseout, INPUT);

   digitalWrite(S0, HIGH); // Output Frequency Scaling set to 20%
   digitalWrite(S1, LOW);  // because there is no filter (clear) initially
   Serial.begin(9600); // Baud rate set to 9600
}

void loop()
{   
    // Red filters set to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    
    // Reading the output frequency
    
    frequency = pulseIn(senseout, LOW); // PulseIn reads a pulse (HIGH or LOW). Look here : StackExchange
    frequency = map(frequency, 25,72,255,0); // Remaping as per the RGB Model 
   
    Serial.print("R= "); 
    Serial.print(frequency); // Printing red color frequency
    Serial.print("  ");
    delay(100); // delay of 100 milli seconds

    // Green filters set to be read    

    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);

    frequency = pulseIn(senseout, LOW);
    frequency = map(frequency, 30,90,255,0);

    Serial.print("G= ");
    Serial.print(frequency);
    Serial.print("  ");
    delay(100);

    // Blue filters set to be read

    digitalWrite(S2, LOW);
    digitalWrite(S3,HIGH);

    frequency = pulseIn(senseout, LOW);
    frequency = map(frequency, 25,70,255,0);

    Serial.print("B= ");
    Serial.print(frequency);
    Serial.println("  ");
    delay(100);
}
