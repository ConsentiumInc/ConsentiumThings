/***************************************************
  This is Consentium's IoT library
  ----> https://docs.consentiuminc.online/
  Check out the links above for our tutorials and product diagrams.

  This Consentium's IoT library works only for ESP8266/ESP32/Raspberry Pi Pico W compatible Edge boards. 
  
  Connect a LED to GPIO 16 for ESP 8266, GPIO 23 for ESP 32 and GPIO 25 for Raspberry Pi Pico W to indicate the REST events. 
  
  Connect analog devices to A0 for ESP 8266, GPIO 34 for ESP 32 and GPIO 26 for Raspberry Pi Pico W using alias ADC_IN. 

  Written by Debjyoti Chowdhury for Consentium IoT.
  MIT license, all text above must be included in any redistribution
 ****************************************************/


#include <ConsentiumThings.h>

ConsentiumThingsDalton board; // Create ConsentiumThings object

const char *ssid = "YOUR_WIFI_SSID"; // Add WiFi SSID
const char *pass = "YOUR_WIFI_PASSWORD"; // Add WiFi password
constexpr int interval = 7000; // Wait for 7 seconds
const char *SendApiKey = "YOUR_API_KEY"; // Send API key
const char *BoardApiKey = "YOUR_BOARD_API_KEY"; // Board API key

void setup() {
  board.initWiFi(ssid, pass); // Begin WiFi connection
  board.beginSend(SendApiKey, BoardApiKey); // Initialize IoT board
}

void loop(){
  double data_0 = 1.0;  // send sample data
  
  vector <double> sensorValues = {data_0};  // sensor data vector
  const char* sensorInfo[] = {"Temperature"}; // sensor info. array
    
  board.sendData(sensorValues, sensorInfo, LOW_PRE); // send over REST with delay with desired prescision

  delay(interval);
}
