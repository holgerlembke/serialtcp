// inline guard. Did I mention that c/c++ is broken by design?
#ifndef serialTCP_h
#define serialTCP_h

#include "Arduino.h"
#include <inttypes.h>
#include "Print.h"

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#ifdef ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#else
#error I don´t know this Wifi-platform.	
#endif
#endif




#include <WiFiUdp.h>

class serialUDP : public Print
{
  private:
    String _ip;
    uint16_t _port;
    WiFiUDP _client;
	bool _active;
    
  public:
    serialUDP();
    virtual ~serialUDP();

    size_t write(uint8_t data);
    size_t write(const char *str);
    size_t write(const uint8_t *buffer, size_t size);

    void begin(long baud, String ip, uint16_t port, bool reconnect = true);
	void begin();
	void end();
};

extern serialUDP SerialUDP;


class serialTCP : public Print
{
  private:
    String _ip;
    uint16_t _port;
    WiFiClient _client;
    bool _reconnect;
	bool _active;
    
    void opentcp();
    void closetcp();
  public:
    serialTCP();
    virtual ~serialTCP();

    size_t write(uint8_t data);
    size_t write(const char *str);
    size_t write(const uint8_t *buffer, size_t size);

    void begin(long baud, String ip, uint16_t port, bool reconnect = true);
	void begin();
	void end();
};

extern serialTCP SerialTCP;


#endif

