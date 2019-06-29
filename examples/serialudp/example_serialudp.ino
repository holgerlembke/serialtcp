#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#ifdef ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#else
#error I don't know this Wifi-platform.  
#endif
#endif

#include <serialtcp.h>

// This will compile for "Wifi" enabled plattforms online.
// For me these are ESP8266 and ESP32 currently. Sorry. Send me hardware if you want to change it.

void setup() {
  // the usual Serial stuff....
  Serial.begin(9600);
  while (! Serial) {
    delay(1);
  }
  Serial.print(F("Hello World!"));

  // login into WiFi
  WiFi.begin("ssid","pwd");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1);
  }

  // after connecting into the WiFi, open it again
  SerialUDP.begin(9600,"1.2.3.4",2345);
  SerialUDP.print(F("Hello again"));
}

void loop() {
  // put your main code here, to run repeatedly:

}
