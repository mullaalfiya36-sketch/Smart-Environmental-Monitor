#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- Pin & sensor setup ---
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// LCD at I2C address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Non-blocking timing ---
unsigned long previousMillis = 0;
const long interval = 2000; // 2 seconds, per DHT22's minimum sampling rate

void setup() {
  Serial.begin(115200);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(1000); // one-time delay is fine here, only runs once in setup
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature(); // Celsius

    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor!");
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error   ");
      lcd.setCursor(0, 1);
      lcd.print("Check wiring    ");
      return;
    }

    // Serial Monitor output
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C  |  Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // LCD output
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print(" C   ");

    lcd.setCursor(0, 1);
    lcd.print("Hum:  ");
    lcd.print(humidity, 1);
    lcd.print(" %   ");
  }

  // rest of the loop stays free for other tasks — that's the whole point of millis()
}