#include "Arduino.h"
#include <inttypes.h>
#include "serialTCP.h"

serialTCP SerialTCP;

//*************************************************************************************
serialTCP::serialTCP() {}

serialTCP::~serialTCP() {
  closetcp();
}

//*************************************************************************************
size_t serialTCP::write(uint8_t data)
{
  if (! _client) {
    opentcp();	
  }

  if (_client) {
    _client.write(data);
  }	
	
  Serial.write(data);

  return 1;
}

//*************************************************************************************
void serialTCP::opentcp()
{
  if (_ip!="") {
    if (!_client.connect(_ip.c_str(),_port)) {
      Serial.println("Debug cant open ");
	  if (! _reconnect) {
		  _ip="";
	  }
      return;
    }
  }
}

//*************************************************************************************
void serialTCP::closetcp()
{
  if (_client) {
    _client.stop();
  }
}

//*************************************************************************************
void serialTCP::begin(long baud, String ip, uint16_t port, bool reconnect)
{
	_port=port;
	_ip=ip;
	_reconnect=reconnect;
	closetcp();
}