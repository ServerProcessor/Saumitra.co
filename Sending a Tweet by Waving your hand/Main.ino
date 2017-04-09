#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

int led= 13;
int sensepin= 2; // D4 is GPIO2
int state=LOW; // Assuming No motion initally
int value= 0; // Variable which stores status of the sensor

String API = "XXXXXXXX"; // Enter your ThingSpeak API
            

// Enter your ssid and password
const char* ssid = "XXXXX"; // SSID (Service Set Identifier) is the name of the WiFi network you want to connect to
const char* password = "******";

WiFiClient client;

void setup() 
 {
    pinMode(sensepin, INPUT); 
  
    pinMode(led,OUTPUT);
 
    WiFi.begin(ssid, password); // Initializes the WiFi library's network settings and provides the current status


    // allow time to make connection
    while (WiFi.status() != WL_CONNECTED) // WiFi.begin returns WL_CONNECTED when connected to a network. We are basically waiting for the connection.
    delay(500);

    value= digitalRead(sensepin); // Read PIR value
    if( value == HIGH )
     {
      digitalWrite(led, HIGH); // Turn LED on
      delay(100); // Delay of 100 milliseconds
      
       if( state == LOW)
         {
            
            String tweet = "Motion-Detected!";
          
        if (client.connect("184.106.153.149", 80)) // Connects to a specified IP address and port
           {
              client.print("GET /apps/thingtweet/1/statuses/update?key=" + API + "&status=" + tweet + " HTTP/1.1\r\n");
              client.print("Host: api.thingspeak.com\r\n");
              client.print("Accept: */*\r\n");
              client.print("User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n");
              client.print("\r\n");
            }
         }

      }
      }

void loop()
{
    
}
