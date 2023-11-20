/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;

const char* ssid = "Team7"; //put ssid from server code
const char* password = "T3@m7password"; //put password from sever code

//Your IP address or domain name with URL path
const char* serverNameBlue = "http://192.168.4.1/bluebutton"; 
const char* serverNameWhite = "http://192.168.4.1/whitebutton";
const char* serverNameRed = "http://192.168.4.1/redbutton";
const char* serverNameYellow = "http://192.168.4.1/yellowbutton";

String BlueValString;
int BlueVal;
String WhiteValString;
int WhiteVal;
String RedValString;
int RedVal;
String YellowValString;
int YellowVal;

// update pins as needed for your particular configuration
// recall the pin numbers refer to the GPIO names, not to the names written on the board
int BlueLEDPin = 12;
int WhiteLEDPin = 14;
int RedLEDPin = 4;
int YellowLEDPin = 5;

void setup() {
  pinMode(BlueLEDPin,OUTPUT);
  pinMode(WhiteLEDPin,OUTPUT);
  pinMode(RedLEDPin,OUTPUT);
  pinMode(YellowLEDPin,OUTPUT);
  
  Serial.begin(115200);
  Serial.println();
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  //Serial.println(WiFi.status());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
}

void loop() {
    if ((WiFiMulti.run() == WL_CONNECTED)) {
      BlueValString = httpGETRequest(serverNameBlue);
      BlueVal = BlueValString.toInt();
      digitalWrite(BlueLEDPin,BlueVal);

      WhiteValString = httpGETRequest(serverNameWhite);
      WhiteVal = WhiteValString.toInt();
      digitalWrite(WhiteLEDPin,WhiteVal);

      RedValString = httpGETRequest(serverNameRed);
      RedVal = RedValString.toInt();
      digitalWrite(RedLEDPin,RedVal);

      YellowValString = httpGETRequest(serverNameYellow);
      YellowVal = YellowValString.toInt();
      digitalWrite(YellowLEDPin,YellowVal);
      
      Serial.println("Blue Button Val is: " + BlueValString + " | WhiteButton Val is: " + WhiteValString + " | Red Button Val is: " + RedValString + " | Yellow Button Val is: " + YellowValString);       
      
      
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  //}
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
//    Serial.print("HTTP Response code: ");
//    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
