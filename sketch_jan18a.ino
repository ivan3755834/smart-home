#include (tg://search_hashtag?hashtag=include) <DHT.h> 
#include (tg://search_hashtag?hashtag=include) <LiquidCrystal_I2C.h> 

#define (tg://search_hashtag?hashtag=define) DHT_PIN 4  // измените на подходящий пин
#define (tg://search_hashtag?hashtag=define) DHT_TYPE DHT22 
DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);  // проверьте адрес вашего дисплея

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight(); 
  lcd.setCursor(0, 0);
  lcd.print("DHT22 LCD Test");
  delay(2000);
}

void loop() {
  float humidity = dht.readHumidity(); 
  float temperature = dht.readTemperature(); 
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error DHT22!!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error DHT22!");
  } else {
    Serial.print("Hum: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.println(" *C");

    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C  ");  // выравнивание
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity);
    lcd.print(" %  ");  // выравнивание
  }
  delay(2000); 
}