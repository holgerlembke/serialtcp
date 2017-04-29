# serialUDP
send debug data to serial port and via udp packets to a listener (made for esp8266/esp32)

Using it is simple: after establishing the wifi-connection call
```
  SerialUDP.begin(115200,"1.2.3.4",1111);  
  SerialUDP.println("Test");
```
# listener
made for powershell

Usage: load the function, than call it.
```
 . .\listen.ps1
  udplisten -p 1111 -ip 1.2.3.4
```

# serialTCP
send debug data to serial port and via tcp connection to a listener (made for esp8266/esp32)

Using it is simple: after establishing the wifi-connection call
```
  SerialTCP.begin(115200,"1.2.3.4",1111);  
  SerialTCP.println("Test");
```
# listener
made for powershell

In case you need to set the execution policy before:
```
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
```

Usage: load the function, than call it.
```
 . .\listen.ps1
 tcplisten -p 1111 -ip 1.2.3.4
```
 
 
