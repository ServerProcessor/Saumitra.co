int led = 13;
int xpin = A0;
int ypin = A1;
int zpin = A2;

void setup()
 {
    Serial.begin(9600);  // Baud Rate of 9600
    pinMode(led, OUTPUT); // Declare pin 13 as output
 }

void loop()
 {
    // Read the 3 values
    int xval = analogRead(xpin);
    int yval = analogRead(ypin);
    int zval = analogRead(zpin);
    Serial.print(xval);
    Serial.print("  ");
    Serial.print(yval);
    Serial.print("  ");
    Serial.print(zval);
 
/* Values at Rest usually are :

   X ~ 330
   Y ~ 330
   Z ~ 440

However, you might need to test and calibrate your module  */

if(xval < 310 || xval > 350 || yval < 310 || yval > 350 || zval < 380 || zval > 460) 
// Taking a margin of +/- 20
 {
    digitalWrite(led, HIGH); // Light up the LED if there is deviation from the set values
    delay(300);
    digitalWrite(led, LOW);
 }

delay(50); // Time for sensor to measure next incoming data

}
