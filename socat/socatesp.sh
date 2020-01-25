#!/bin/bash
# Bei Aufruf eine leere Log-Datei anlegen
# Eventuell existierende Daten werden gelöscht
echo "$ts ### START ###" > /tmp/socatesp.log

# Daten per UDP auf Port 1111 einlesen
# Jede Zeile in die while Schleife pipen und dort weiterverarbeiten 
socat - udp-listen:1111 |
while read line
do {
  # Datum holen, konvertieren in Stunde:Minute:Sekunde:Nanosekunde und auf 12 Stellen Länge kürzen
  ts=`date +"%T:%N" | cut -c 1-12`
  # Datum in [] setzen und die von socat erhaltene Zeile anhängen und in Datei schreiben
  echo "[$ts] $line" >> /tmp/socatesp.log
  #echo "[$ts] $line"
} done

# Wenn die Daten nicht nur im Log landen sollen, sondern man diese gleichzeitig betrachten möchte,
# kann man entweder eine zweite "echo" Zeile einfügen
# oder die Datei mit folgendem Befehl fortlaufend auf einer (anderen) Konsole ausgeben
# tail -f /tmp/socatesp.log

# freundlicherweise zur Verfügung gestellt von H. R.
