// Youssef Selkani 2021

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "dht.h"

#define dht_apin A1
dht DHT;
int sensorPin = A0;
int sensorValue;
int limit = 300;
const byte LCDcolumns = 16;
const byte LCDrows = 2;
LiquidCrystal_I2C lcd(0x27, LCDcolumns, LCDrows);

const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  delay(500);
  Wire.begin();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Febys");
  lcd.setCursor(0, 1);
  lcd.print("v0.1 ");
  lcd.blink();
  delay(6000);
}

void loop()
{
  //  Relay code
  //  pinMode(12, OUTPUT);
  //  digitalWrite(12,HIGH);
  //  delay(2000);
  //  digitalWrite(12,LOW);

  lcd.clear();
  lcd.noBlink();
  sensorValue = analogRead(sensorPin);
  lcd.print("Soil Moisture");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
  lcd.print(" KPI");

  delay(2000);
  lcd.clear();

  if (sensorValue < limit) {
    lcd.print("Soil health");
    lcd.setCursor(0, 1);
    lcd.print("OK");
  }
  else {
    lcd.print("Soil health");
    lcd.setCursor(0, 1);
    lcd.print("Needs water ...");

  }

  delay(2000);
  lcd.clear();

  DHT.read11(dht_apin);
  lcd.print("Current humidity");
  lcd.setCursor(0, 1);
  lcd.print(DHT.humidity);
  lcd.print(" %");

  delay(2000);
  lcd.clear();

  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print(DHT.temperature);
  lcd.print(" C");
  lcd.print((char) 223);


  delay(2000);
  lcd.clear();
  lcd.blink();
  delay(9000);

}
