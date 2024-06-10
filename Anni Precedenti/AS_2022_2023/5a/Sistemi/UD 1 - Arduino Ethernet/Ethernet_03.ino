#include <SPI.h>
#include <Ethernet.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

#define DELTA_READ 10000
#define DELTA_WRITE 60000
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 5, 210 };
byte subnet[] = { 255, 255, 240, 0 };
byte dns[] = { 8, 8, 8, 8 };
byte gateway[] = { 192, 168, 0, 254}; // gateway di casa 

byte server[] = {192, 168, 5, 200};

EthernetClient shield;
int cnt;
int time_read;
int time_write;
int random_value;



void setup() {
  Serial.begin(9600);
  delay(1000);  
  cnt = 1;
  time_read = millis();
  time_write = millis();
}

void loop() {
  int n_byte;

// BLOCCO DI RICHIESTA VALORE
  if(millis()-time_read > DELTA_READ){
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
    time_read = millis();
  }

// BLOCCO DI SCRITTURA VALORE RANDOM SU SERVER
  if(millis()-time_write > DELTA_WRITE){
    random_value = 1 + rand()%100;
    String url = "GET /ardushield.php?scelta=addValue&value=";
    //char url[] ="GET /ardushield.php?&scelta=addValue&value=";
    url += String(random_value);
    Ethernet.begin(mac, ip);
    delay(1500);
    Serial.println("Ready to send to server...");
    Serial.print("Try nr.: #");
    Serial.println(cnt);
    if(shield.connect(server, 80)){
      Serial.print("Connessione ok to: ");
      Serial.println(url);
      Serial.println(shield.remoteIP());
      //shield.println("GET /ardushield.php?&scelta=addValue&value=33");
      shield.println(url);
      Serial.println("Chiusura chiamata HTTP...");
    }
    else{
      Serial.println("Errore in connessione...");
    }
    time_write = millis();
  }  
}
