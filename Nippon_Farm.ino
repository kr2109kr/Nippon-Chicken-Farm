#define BLYNK_TEMPLATE_ID "1234"
#define BLYNK_TEMPLATE_NAME "1234"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "*************"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "NIPPONPC 6338";
char pass[] = "55555555";

BlynkTimer timer;

//------------------------------------------------------------------------------
// This function is called every time the device is connected to the Blynk.Cloud
// Request the latest state from the server
BLYNK_CONNECTED() {
  
}

void setup() {
  
  Serial.begin(9600);

  SetupDHT();
  SetupRelay();

  timer.setInterval(1000, ReadDHT);
  timer.setInterval(1000, ReadMQ);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();
}