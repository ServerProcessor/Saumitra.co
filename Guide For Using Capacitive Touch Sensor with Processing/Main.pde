import processing.serial.*;
Serial port;
float capacitive= 0;
void setup()
{
  size(1023,1023);
  
  String portName = Serial.list()[0];
  port = new Serial(this,portName,9600); // Serial(parent,portName,BaudRate)
  port.bufferUntil('\n');
}
void draw()
{
  background(0,0,(capacitive*1023));  // Multiplying by 1023 because capacitive returns 1 in case of touch ( can be neglected if using an analog pin )
}

void serialEvent(Serial port)
{
  capacitive = float(port.readStringUntil('\n'));
  println(capacitive);  // To print the value on the Processing screen
}
