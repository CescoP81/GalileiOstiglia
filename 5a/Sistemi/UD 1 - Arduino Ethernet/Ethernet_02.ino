/*
  Esempio di utilizzo della Ethernet Shield W5100 e di un display Oled I2C SSD1306 Monocromatico (Az-Delivery).
  L'esempio prevede che il server abbia indirizzo: 192.168.5.200
  La Ethernet shield IP: 192.168.5.210
  Sul Server sia installato uno XAMPP e nella root via sia una pagina ardushield.php che esegua una semplice echo(); di un valore numerico.

  Da tener conto:
  a. Il display OLED ha una matrice 128x64 pixels, non è possibile allocarla totalmente ed allo stesso tempo utilizzare la ethernet shield.
      Per questo motivo l'oled viene allocato come 128x32 pixels. Diversamente è richiesto l'utilizzo di un Arduino UNO MEGA R3 equipaggiato con maggiore memoria.
  b. Tra una chiamata e la successiva al server da parte della shield impostare un delay di almeno 5000ms (5 secondi), se inferiore alcune chiamate non vengono evase.
*/
#include <SPI.h>
#include <Ethernet.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 5, 210 };
byte subnet[] = { 255, 255, 240, 0 };
byte dns[] = { 8, 8, 8, 8 };
byte gateway[] = { 192, 168, 0, 254}; // gateway di casa 

byte server[] = {192, 168, 5, 200};

EthernetClient shield;
int cnt;

void setup() {
  // put your setup code here, to run once:
  /*if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    while(true);
  }
  delay(1000);
  display.clearDisplay();
  display.display();
  display.setTextColor( WHITE);
  display.setTextSize(2);
  display.setCursor(0, SCREEN_HEIGHT / 2);
  display.print("INIT... ");
  display.display();
  // */
  Serial.begin(9600);
  delay(1000);  
  cnt = 1;
}

void loop() {
  int n_byte;

  Ethernet.begin(mac, ip);
  delay(1500);
  Serial.println("Ready to call server...");
  Serial.print("Try nr.: #");
  Serial.println(cnt);
  if(shield.connect(server, 80)){
    Serial.print("Connessione ok to: ");
    Serial.println(shield.remoteIP());
    shield.println("GET /ardushield.php");
    Serial.println("Chiusura chiamata HTTP...");
  }
  else{
    Serial.println("Errore in connessione...");
  }

  n_byte = shield.available();
  Serial.print("Byte: ");
  Serial.print(n_byte);
  Serial.print(" - Random: ");

  //display.clearDisplay();
  //display.display();
  //display.setCursor(0, SCREEN_HEIGHT / 2);
  int val = 0;
  while(shield.available()){
    char c = shield.read();
    val = (val * 10) + (c - 48);
    Serial.print(c);
    //display.print(c);
  }
  //display.display();
  Serial.println();
  Serial.println();
  shield.stop();
  shield = NULL;

  int x = display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  if(!x){
    Serial.print("No Display Oled: ");
    Serial.println(x);
  }
  display.clearDisplay();
  display.display();
  display.setTextColor( WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("RANDOM: ");
  display.print(val);
  display.display();
  //*/

  cnt++;
  delay(10000);
}