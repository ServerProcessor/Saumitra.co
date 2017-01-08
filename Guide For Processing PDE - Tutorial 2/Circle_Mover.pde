int x = 200;

void setup()
 {
   size(480,120);
   fill(255,0,0);
 }

void draw()
{
   if(keyPressed && ( key == CODED ) ) // Check whether the key is coded ( Arrow keys , Shift , etc )
    {
      if ( keyCode == LEFT )
       {
         x--;
       }
      if( keyCode == RIGHT )
       {
         x++;
       }
    }
  ellipse(x,50,80,80);
}
