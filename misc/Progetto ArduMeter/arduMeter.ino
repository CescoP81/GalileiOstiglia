/*
  Author: Baroni Mattia
  Date:   25.01.2024
  Description:
  Applicazione per la rilevazione di temperatura e umidità con cadenza oraria e salvataggio in una tabella su database.

  Hardware:
  - Aurduino UNO R3 board.
  - Ethernet Shield 5100 by KeyeStudio
  - DHT11 Sensor Temperature & Humidity by KeyeStudio.

  Externar Resources:
  - Server locale o remoto con supporto PHP/MySQL.

  Libraries:
  - Ethernet by Variuous Ver. 2.0.2
  - DHTLib by Rob Tillaart Ver. 0.1.36
*/
  
#include <SPI.h>
#include <Ethernet.h>
#include <dht.h>

//---- costanti per asincronicità e valori
#define DHT11_PIN 5
unsigned long startMillis; 
unsigned long currentMillis;
const unsigned long period = 900000;  //15 minuti 1000*60*15

float temp;
float hum;

//---- sensori e connessioni ---
EthernetClient cli;
dht DHT;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192, 168, 6, 200};
byte server[] = { 192, 168, 6, 74 };
char serverRemote[] = "francescopradella.it";
String httpUrl;


void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  Serial.println("Connecting to the ethernet infrastructure...");
  delay(5000);        // delay impostato per attendere la pubblicazione della scheda di rete e l'acquisizione di IP, Gateway, Subnet mask e DNS.
  startMillis = 0;  
}

void loop() {
  if((startMillis==0) || (millis() - startMillis >= period)){
    getTemp(&temp, &hum);
    if (int e = cli.connect(serverRemote, 80)){
      Serial.println("connected");
      httpUrl = "GET /arduino/temperatura.php?scelta=addtemp&temp=";
      httpUrl += temp;
      httpUrl += "&umid=";
      httpUrl += hum;
      httpUrl += " HTTP/1.0";
      Serial.println(httpUrl);
      cli.println(httpUrl);
      cli.println("Host: www.francescopradella.it");  //aggiunto header finale per server remoto.
      cli.println();
    }
    else{
      Serial.print("uscita con errore: ");
      Serial.println(e);
    }

    /* Attendo due secondi la risposta del server remoto, quindi stampo la risposta ottenuta char-by-char nel monitor seriale della IDE */
    delay(2000);
    while (cli.available()) {
      char c = cli.read();
      Serial.print(c);
    }
    Serial.println();
    Serial.println("--------------------");

    cli.stop();
    startMillis = millis();
  } 
}

/*
  Funzione che legge temperatura e umidità dal sensore DHT11
  @param float* Riferimento alla variabile per lo store della temperatura.
  @param float* Riferimento alla variabile per lo store dell'umidità
*/
void getTemp(float *_temp, float *_hum){
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);

  switch (chk){
    case DHTLIB_OK:  
    Serial.print("OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Time out error,\t"); 
    break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
    Serial.print("Unknown error,\t"); 
    break;
  }

  // salvataggio dei valori letti nelle variabili originali della funzione LOOP e relativa stampa nel monitor seriale della IDE.
  *_hum = DHT.humidity;
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");

  *_temp = DHT.temperature;
  Serial.println(DHT.temperature, 1);
}

