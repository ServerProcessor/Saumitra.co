int xpin = 0;
int ypin = A1;
int button_key = 3;
int button_value;

void setup()
{
  pinMode(button_key,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int xval,yval,buttonval;
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  button_value = digitalRead(button_key);

  Serial.print("xval  ");
  Serial.println(xval,DEC);
  Serial.print("yval  ");
  Serial.println(yval,DEC);

  Serial.print("Button is  ");
  if(button_value == HIGH)
  {
    Serial.println("Not Pressed");
  }
  else
  {
    Serial.println("Pressed");
  }
  delay(500);
}
