#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
//#include <hd44780.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
dht sensor;
const int DHT_PIN = 8;

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT and HD44780LCD Test");
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.clear();
  int chk = sensor.read(DHT_PIN);
  Serial.println(chk);

  lcd.setCursor(0, 0);
  lcd.print("ArduMeter Station");

  lcd.setCursor(0, 1);
  lcd.print("Temperature: ");
  lcd.print(sensor.temperature, 1);
  
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(sensor.humidity, 1);

  delay(5000);  
  /*
  lcd.setCursor(0, 0);
  lcd.print(" How Use Display :)");
  lcd.setCursor(2, 1);
  lcd.print(" Hd44780 i2c");
  lcd.setCursor(2, 2);
  lcd.print("16x2 and 20x4 ");
  lcd.setCursor(1, 3);
  lcd.print(" ForbiddenBit.com ");
  */
}
