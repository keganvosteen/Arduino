/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

// Import required libraries 
#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"


// Set your access point network credentials
const char* ssid = "Team7"; //create a server name (the wifi name you will connect to)
const char* password = "T3@m7password"; //create a unique password that you and your teammates know

// Create AsyncWebServer object on port 80
// In our case, we will use port 80, which is the default HTTP port. 
// Thus, since our client will be a web browser, 
// it will use port 80 by default and we don’t need to explicitly specify it. 
// In case we use a port different than 80, 
// we need to specify it when contacting the server using a web browser.
AsyncWebServer server(80); //asynchronous web server allows other things to happen after signal is sent

// update pins as needed for your particular configuration
// recall the pin numbers refer to the GPIO names, not to the names written on the board
int BlueButtonPin = 12;
int WhiteButtonPin = 14;
int RedButtonPin = 4;
int YellowButtonPin = 5;

int BlueVal = 0;  
int WhiteVal = 0;    
int RedVal = 0;
int YellowVal = 0;


String readBlueButton() {
  BlueVal = digitalRead(BlueButtonPin);
  Serial.print("Blue Button Val is: ");
  Serial.println(BlueVal);

  return String(BlueVal);
}

String readWhiteButton() {
  WhiteVal = digitalRead(WhiteButtonPin);
  Serial.print("White Button Val is: ");
  Serial.println(WhiteVal);

  return String(WhiteVal);

}

String readRedButton() {
  RedVal = digitalRead(RedButtonPin);
  Serial.print("Red Button Val is: ");
  Serial.println(RedVal);

  return String(RedVal);
}

String readYellowButton() {
  YellowVal = digitalRead(YellowButtonPin);
  Serial.print("Yellow Button Val is: ");
  Serial.println(YellowVal);

  return String(YellowVal);
}

void setup(){
  pinMode(BlueButtonPin,INPUT);
  pinMode(WhiteButtonPin,INPUT);
  pinMode(RedButtonPin,INPUT);
  pinMode(YellowButtonPin,INPUT);   
  
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();

  Serial.println("you are here");
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP); // Make sure to note down the IP address! 

  /*
   * Then, handle the routes where the ESP8266 will be listening for incoming requests.

    For example, when the ESP8266 server receives a request on the /bluebutton URL, 
    it sends the string returned by the blueButton() 
    function as a char (that’s why we use the c_str() method.
   */


  // server.on
  server.on("/bluebutton", HTTP_GET, [] (AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBlueButton().c_str());
  });

  server.on("/whitebutton", HTTP_GET, [] (AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readWhiteButton().c_str());
  });

  server.on("/redbutton", HTTP_GET, [] (AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readRedButton().c_str());
  });

  server.on("/yellowbutton", HTTP_GET, [] (AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readYellowButton().c_str());
  });
  
  // Start server
  server.begin();
}
 
void loop(){
  
}
