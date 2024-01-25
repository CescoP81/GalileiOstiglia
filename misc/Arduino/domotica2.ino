#include <SPI.h>
#include <Ethernet.h>

// ##############################
// Variabili per la ethernet shield come client.
// ##############################
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(192, 168, 5, 200);  // numeric IP laptop.
IPAddress ip(192, 168, 5, 202);
EthernetClient client;

void setup() {
  // ##########################
  // #     PREPARO I LED      #
  // ##########################
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // #########################
  // #  INIT DELLA ETHERNET  #
  // #########################
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  delay(1000);
  Serial.print("Ready for connections... ");
  Serial.print(server);
  Serial.println("...");  
}

void loop() {
  // ##########################################
  // #       PREPARING MAIN VARIABLES         #
  // ##########################################
  String httpCall="";
  //httpCall = String(httpCall + "GET /scuola/index.php");
  httpCall = String(httpCall + "GET /fpradella/Domotichouse/getstat.php");
  //httpCall = String(httpCall + " HTTP/1.1");

  int n_byte;         // Number of bytes retrieved from server / it could be zero.
  char leds[8];       // The string of 0/1 retrieved from the webserver.
  int i;              

  // #########################################
  // #              THE CORE                 #
  // #########################################            
  Serial.println(httpCall);
  Serial.println();

  if(client.connect(server, 80)){                           // CHECK about connection with server true/false
    
    Serial.print("1- Connesso a: ");
    Serial.println(client.remoteIP());

    //Serial.print("2- Stringa GET: ");
    //Serial.println(httpCall);
    
    //client.println("GET /scuola/index.php");
    client.println(httpCall);                              // sending the request to the server but it could fail
    //client.println("Host: 192.168.80.5");
    //client.println("Connection: close");
    //client.println();

    //int len = client.available();
    //Serial.println(len);
    //client.stop();
    Serial.println("3- Chiusura richiesta GET.");
  }
  else{
    Serial.println("Errore Connessione");
  }

  n_byte = client.available();                              // more than zero if request at line 56 is OK.
    Serial.print("Bytes: ");
    Serial.println(n_byte);
  if(n_byte > 0){                                           // if a string is present I split it into an Array of char.
    Serial.println("5- Devo scomporre il messaggio..."); 
    
    for(i=0; i<n_byte; i++){
      leds[i] = client.read();
      Serial.print("Bit Letto ");
    }  
  }
  Serial.println();
  client.stop();                                            // Closing the connection with the server.
  Serial.print("Stringa Led: ");
  for(i=0; i<n_byte; i++){                                  // Changing the status of each led.
    Serial.print(leds[i]);
    if(leds[i] == '1') digitalWrite(i+2, HIGH);
    else digitalWrite(i+2, LOW);
  }
  Serial.println("\n----- END SESSION ----");
  
  delay(10000);                                             // Delay to next request.
}
