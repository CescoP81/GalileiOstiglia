#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
int cnt;
int yi, yf;
int dy;

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
  //Stampo una scritta
  display.println("INIT... ");
  display.drawLine(0,0,100,50, WHITE);
  //La mando in stampa
  display.display();
  delay(250);
  yi=0;
  yf=63;
  dy = 1;
}

void loop() {
  display.clearDisplay();
  display.display();


  display.setCursor(0, 10);
  display.setTextSize(1);
  //display.println("Oggi il sole e sono felice...");
/*
  display.setCursor(0, 25);
  display.setTextSize(2);
  display.println("Marcheselli");
*/
  display.display();
  
  display.drawLine(0,yi,127,yf, WHITE);
  display.display();
  yi = yi+dy;
  yf = yf-dy;

  if(yi == 0)
    dy = -dy;
  if(yi == 64)
    dy = -dy;
  
  // put your main code here, to run repeatedly:
  /*display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setCursor(3, 3);
  display.println(cnt);
  display.display();
  cnt++;*/
  delay(125);

}
