<#
 endless listening
 
 load with:   PS ... _> . .\listen.ps1
 start with:  PS ... _> listen -p portnumber -ip ipnumbertobindto
#>

function listen($port=2223, $IPAdress="127.0.0.1"){
  $enc = [System.Text.Encoding]::ASCII
  while ($true)
  {
    $listener = new-object System.Net.Sockets.TcpListener([System.Net.IPAddress]::Parse($IPAdress), $port)
    $listener.start()
    [byte[]]$bytes = 0..255|%{0}
    $client = $listener.AcceptTcpClient()
    write-host "<connect> $($client.Client.RemoteEndPoint)"
    $stream = $client.GetStream()
      while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0)
      {
        write-host -NoNewline $enc.GetString($bytes[0..($i-1)])
      }
    $client.Close()
    $listener.Stop()
    write-host "<end>"
  }
}

