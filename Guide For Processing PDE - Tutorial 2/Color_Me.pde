int x;
int y;
int z;

void setup()
{
  size(600,340);
  smooth();
  background(204,180,150);
  noStroke();
}

void draw()
{
     rect(30,20,4,60); 
     rect(30,50,50,4); // Print "H"
     rect(80,20,4,60);  
         
     rect(120,20,4,60); // Prints "I"
  
     rect(30,120,50,4); 
     rect(30,120,4,30);
     rect(30,150,50,4); // Prints "S"
     rect(80,150,4,30);
     rect(80,180,-50,-4);        
  
     rect(120,120,4,60); 
     rect(120,120,30,4);
     rect(150,120,4,60); //  Prints "A"
     rect(120,150,30,4);            
  
     rect(180,120,4,60); 
     rect(180,180,40,4); //  Print "U"
     rect(220,120,4,60); 
          
     alpha();
     fill(x,y,z);
}

void alpha()
{
  if(mouseX > 20 && mouseX <180 || mouseY > 20 && mouseY < 180)
   {
     x = 100;
     y = 180;
     z = 180;
   }
  else
   {
     x = 0;
     y = 0;
     z = 0;
   }
}
