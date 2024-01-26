/*
  Author: Francesco Pradella
  Description: Sketch con utilizzo della libreria AdaFruit e Oled 128x64 I2C.
  Disegna una linea che in loop si inclina nello schermo variando la coordinata Y ad inizio e fine segmento.

  Latest Test:  26.01.2024
  Board:        Arduino Mega 2560+ Keyestudio
  LCD:          Oled 128x64 I2C AZDelivery

  Library:
  Adafruit_GFX Ver. 1.11.19
  Adafruit_SSD1306 Ver. 1.5.9
*/
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
int cnt;
int yi, yf;
int dy;

unsigned long oldTime;            // Last changing status time.
unsigned long timePeriod = 250;  // milliseconds for temporization.

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    while(true);
  }
  delay(1000);
  display.clearDisplay();
  display.display();

  //Setto il colore del testo a "bianco"
  display.setTextColor( WHITE);
  //Setto dimensione del testo
  display.setTextSize(1);
  //Sposto il cursore a metà altezza del display
  display.setCursor(0, SCREEN_HEIGHT / 2);
  //Stampo una scritta iniziale di inizializzazione oled
  display.println("INIT... Please Wait!");
  //La mando in stampa [pubblico il buffer di memoria dell'lcd]
  display.display();

  // coordinate Y di partenza degli estremi della linea e delta spostamento sull'asse Y.
  yi = 0;
  yf = 63;
  dy = 1;
  delay(3000);
  oldTime = millis();
}

void loop() {
  if(millis() - oldTime > timePeriod){
    newLine(&yi, &yf, &dy);
    oldTime = millis();
  }

}

void newLine(int *_yi, int *_yf, int *_dy){
  display.clearDisplay();
  display.display();
  
  display.drawLine(0, *_yi, 127, *_yf, WHITE);
  display.display();
  *_yi = *_yi + *_dy;
  *_yf = *_yf - *_dy;

  if(*_yi == 0)
    *_dy = -(*_dy);
  if(*_yi == 64)
    *_dy = -(*_dy);
}