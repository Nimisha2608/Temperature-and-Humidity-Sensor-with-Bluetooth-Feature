#include <LiquidCrystal.h>


#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // RX, TX

#include <LiquidCrystal.h> 
#include "dht.h"
#define dataPin A0
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
dht DHT;

float temp;
float hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 
  
  lcd.begin(16,2);  
  lcd.setCursor(0,0);
  lcd.print(" GROUP 16");
  delay(2000);
  lcd.clear(); 
}

void loop(){
  float readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;
  
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("% ");

  lcd.setCursor(0,1); 
  lcd.print("Temp: "); 
  lcd.print(temp); 
  lcd.print((char)223); //degree symbol
  lcd.print("C ");

 bt.print(temp); //send distance to MIT App
 bt.print(";");
 bt.print(hum); //send distance to MIT App 
 bt.println(";");
  
  delay(1000);
}
