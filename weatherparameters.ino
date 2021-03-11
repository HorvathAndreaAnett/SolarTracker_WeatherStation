#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to

dht DHT;
int hum;
int temp;
int rainSensVal;

LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup()
{
  Serial.begin(9600);
  delay(500);
  lcd.begin(16,2);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Weather station");
  delay(5000);
  
}

void loop()
{
  DHT.read11(dht_apin);
  rainSensVal = analogRead(A1);

  ///////////////////TEMPERATURE & HUMIDITY//////////////////////
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  
  hum = DHT.humidity;
  lcd.print(hum);

  Serial.println("Humidity: ");
  Serial.print(DHT.humidity);
  
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  
  temp = DHT.temperature;
  lcd.print(temp);

  Serial.println("Temperature: ");
  Serial.print(temp);
  
  delay(5000);

  /////////////////////RAIN DETECTION/////////////////////////

  Serial.println("Rain sensor: ");
  Serial.print(rainSensVal);

  if(rainSensVal > 800){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    NO RAIN ");
  }
  
  if(rainSensVal <= 800 && rainSensVal > 600){
    lcd.setCursor(0,0);
    lcd.print("IT IS RAINING   ");
    lcd.setCursor(0,1);
    lcd.print("AMOUNT: LOW ");
  }

  if(rainSensVal <= 600 && rainSensVal > 460){
    lcd.setCursor(0,0);
    lcd.print("IT IS RAINING   ");
    lcd.setCursor(0,1);
    lcd.print("AMOUNT: MEDIUM ");
  }

  if(rainSensVal < 460){
    lcd.setCursor(0,0);
    lcd.print("IT IS RAINING   ");
    lcd.setCursor(0,1);
    lcd.print("AMOUNT: HIGH    ");
  }

  delay(5000);
  
}