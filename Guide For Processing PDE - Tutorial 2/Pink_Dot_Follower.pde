void setup()
{
  size(480,120);
  fill(200,150,150);
  smooth();
  noStroke();
}

void draw()
{
  background(220);
  ellipse(mouseX, mouseY, 15, 15); // X and Y coordinates updated with mouseX and mouseY
  println(mousex,mouseY); // Print the coordinates
}
