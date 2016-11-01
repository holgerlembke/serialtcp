# serialtcp
send debug data to serial port and via tcp connection to a listener (made for esp8266/esp32)

Using it is simple: after establishing the wifi-connection call
```
  SerialTCP.begin(115200,"1.2.3.4",1111);  
  SerialTCP.println("Test");
```
# listener
made for powershell

Usage: load the function, than call it.
```
 . .\listen.ps1
 listen -p 1111 -ip 1.2.3.4
```
 
 
