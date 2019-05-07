/*
 * Getting started with IoTEazy.com
 * Sending sensor data to the cloud
 * Written by - Shivam Gautam
 * https://github.com/shivamgpio/IotEazy-esp8266-sendData
 */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


const char* ssid = "WiFiName";//Your WiFi Name
const char* password = "WiFiPass";//WiFi Password

String apiKey = "API_KEY_HERE";//Your API Key here
String deviceId = "DEVICE_ID_HERE";//Device Id here

float readTemp(){
  int analogValue = analogRead(A0);
  float millivolts = (analogValue/1024.0) * 3300;
  float celsius = millivolts/10;
  Serial.println("");
  Serial.print("Current temperature is: ");
  Serial.println(celsius);
  return celsius;
}

void setup() {
  Serial.begin(115200);//Begin Serial Comm
  WiFi.begin(ssid, password);//Start WiFi with Credentials
  //Show connecting while esp tries to connect to WiFi
  Serial.println("");
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
  delay(250);
  Serial.print(".");
  }

}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    int temp = readTemp();//Read sensor here
    HTTPClient http;
    //Create Request URL
    String sendReq = "http://rest.ioteazy.com/request/";
    sendReq += apiKey;
    sendReq += "/send/analogsense/";
    sendReq += deviceId;
    sendReq += "/";
    sendReq += temp;

    http.begin(sendReq);
    int httpCode = http.GET();

    if(httpCode > 0){
      String payload = http.getString();
      Serial.println(payload);  
    }
    http.end();
  }
  delay(30000);//Send data every 30 sec
}
