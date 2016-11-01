// inline guard. Did I mention that c/c++ is broken by design?
#ifndef serialTCP_h
#define serialTCP_h

#include "Arduino.h"
#include <inttypes.h>
#include "Print.h"
#include <ESP8266WiFi.h>


class serialTCP : public Print
{
  private:
    String _ip;
	uint16_t _port;
    WiFiClient _client;
	bool _reconnect;	
	
	void opentcp();
	void closetcp();
  public:
    serialTCP();
	virtual ~serialTCP();

    size_t write(uint8_t data);
	size_t write(const char *str);
    size_t write(const uint8_t *buffer, size_t size);

    void begin(long baud, String ip, uint16_t port, bool reconnect = true);
};

extern serialTCP SerialTCP;

#endif

