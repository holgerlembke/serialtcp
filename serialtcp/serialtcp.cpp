#include "Arduino.h"
#include <inttypes.h>
#include "serialTCP.h"

//*************************************************************************************
serialTCP::serialTCP() {}

//*************************************************************************************
size_t serialTCP::write(uint8_t data)
{
  Serial.write(data);

  return 1;
}

void serialTCP::opentcp()
{
	
}

void serialTCP::closetcp()
{
	
}

//*************************************************************************************
void serialTCP::begin(long baud, String ip, uint16_t port)
{
	_port=port;
	_ip=ip;
}