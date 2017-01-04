int dataq = 0;
int ot= -1;
int tag1[12]= { X,X,X,X,X,X,X,X,X,X,X,X }; // Place your Card Number here
int tag2[12]= { }; // I left it blank but you can insert another Card Number
int newtag[12]= {0,0,0,0,0,0,0,0,0,0,0,0};

void setup()
{
  Serial.flush(); // Serial.read() reads the data at the front of the queue and Serial.flush clears the entire queue
  Serial.begin(9600);
}

boolean comparetag(int aa[12], int bb[12]) // Compares the tag with tag read
{
  boolean ff= false;
  int fg=0;
  for(int cc=0;cc<12;cc++)
   {
      if(aa[cc]==bb[cc])
       {
         fg++;
       }
    }
      if(fg==12)
       {
         ff= true;
       }
      return ff;
}

void checkmytags()
{
  ot= 0;
  if(comparetag(newtag,tag1)== true)
   {
     ot++;
   }
}

void loop()
{
  ot= -1;
  if(Serial.available()>0) // If there is a read
   {
     delay(100); // Time for the data to come in
     for(int z=0;z<12;z++)
      {
        dataq= Serial.read();
        newtag[z]= dataq;
      }
   Serial.flush();
   checkmytags();
}

if(ot>0) // If matches
{
  Serial.println("Card Accepted!");
  ot=-1;
}
else if(ot==0) // If no match
{
  Serial.println("It is a cruel World, Card Rejected!");
  ot= -1;
}
}
