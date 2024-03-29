# include 

```
  #include <serialTCP.h>
```

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

With multiples sender active, the shell will be flodded with messages. Use
```
 . .\listen.ps1
  udplisten -p 1111 -ip 1.2.3.4 -client 5.6.7.8
```

to focus on one sender.

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
Set-ExecutionPolicy unrestricted -Scope CurrentUser
```

Usage: load the function, than call it.
```
 . .\listen.ps1
 tcplisten -p 1111 -ip 1.2.3.4
```
 
# listener alternatives

socat (SOcket CAT) can listen natively on an UDP port. There are windows binaries, but probably the easier way is to use socat within the linux subsystem of Windows 10. Just turn on the *Windows Feature* Windows Subsystem for Linux, download DEBIAN from the Microsoft Store, log in and install & use socat.

For the unpracticed:
```
  sudo apt-get update
  sudo apt-get install socat
  socat - udp-listen:1111
```
(There *is* an extra space...)

Thanks go to H. R. for pointing out socat.

# Suspend and Resume 

In case you want to suspend sending messages it is safe to call

```
  SerialUDP.end();
```

or

```
  SerialTCP.end();
```

To resume services, simply call

```
  SerialUDP.begin();
```

or

```
  SerialTCP.begin();
```

