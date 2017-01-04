#include <SPI.h> // Header SPI Library
#include <SD.h> // Header SD Library

const int chipselect = 10; // Chip Select Pin

void setup()
 {
   Serial.begin(9600); // Baud Rate = 9600
   while(!Serial) // Wait for the Serial Port to connect
    {
      ;
    }

Serial.print("Initializing SD Card. . .");

if(!SD.begin(chipselect)) // Check if the card is initialized
  {
    Serial.println(" Car Failed or Not Present ");
    return;
  }

Serial.println("Card Initialized");

 }

void loop()
  {
    File dataFile = SD.open("data.txt",FILE_WRITE); // Open the .txt file

    if(dataFile)
      {
        dataFile.println( ---- ); // Write from any relevant sensor or device you wish to
        dataFile.close(); // Only one file can be opened at a time, so close the existing one
      }
   
    else
      {
        Serial.println(" Life is hard and full of errors! "); // If the file is not open
      }

}
