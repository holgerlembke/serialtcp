// inline guard. Did I mention that c/c++ is broken by design?
#ifndef LPT_h
#define LPT_h

#include "Arduino.h"
#include <inttypes.h>
#include "Print.h"

class serialTCP : public Print
{
  private:
    String _ip;
	uint16_t _port;
	
	void opentcp();
	void closetcp();
  public:
    serialTCP();
    size_t write(uint8_t data);

    void begin(long baud, String ip, uint16_t port);
};

#endif
