<#
 endless listening
 
 load with:   PS ... _> . .\listen.ps1
 start with:  PS ... _> listen -p portnumber -ip ipnumbertobindto
 
 any keypress should stop the script (if it is not waiting for connections... needs to be optimized)
#>

function listen($port=2223, $IPAdress="127.0.0.1"){
  $enc = [System.Text.Encoding]::ASCII
  $loop=$true;

  $listener = new-object System.Net.Sockets.TcpListener([System.Net.IPAddress]::Parse($IPAdress), $port)

  while ($loop)
  {
    $listener.start()
    [byte[]]$bytes = 0..255|%{0}
    $client = $listener.AcceptTcpClient()
    write-host "<connect> $($client.Client.RemoteEndPoint)"
    $stream = $client.GetStream()
	$stream.ReadTimeout = 5000 
	try
	{
      while($loop -and $stream -and (($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0) )
      {
        write-host -NoNewline $enc.GetString($bytes[0..($i-1)])
        if ([console]::KeyAvailable)
        {
          $loop = $false 
        } 
      }
    } catch { #ignore everything
	}
    $client.Close()
    $listener.Stop()
    write-host "<end>"
	
    if ([console]::KeyAvailable)
    {
      $loop = $false 
    } 
  }
}

