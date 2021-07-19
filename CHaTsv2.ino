#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHT2PIN 3
#define DHT3PIN 4

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);
DHT dht3(DHT3PIN, DHTTYPE);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Chinchilla T&H!");

  dht.begin();
  dht2.begin();
  dht3.begin();

}

void loop() {
  delay(2000);
  lcd.setCursor(0, 1);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.print("Failed sensor1");
    return;
  }


  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float f2 = dht2.readTemperature(true);
  if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.print("Failed sensor2");
    return;
  }



  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();
  float f3 = dht3.readTemperature(true);
  if (isnan(h3) || isnan(t3) || isnan(f3)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.print("Failed sensor3 ");
    return;
  }


  float temperature = (t+t2+t3)/3;
  float humidity = (h+h2+h3)/3;
  int TandH =  (humidity + (f+f2+f3)/3);

  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(TandH);



  lcd.print( "" );
  lcd.print( temperature, 1 );
  lcd.print( "C " );
  lcd.print( humidity, 1 );
  lcd.print( "% " );
  lcd.print(TandH);

}
