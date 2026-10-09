/*
  Smart Soil Moisture Monitoring System
  Board:   Arduino Uno
  Sensor:  Analog soil moisture sensor
  Outputs: I2C LCD (16x2) and a buzzer

  Behaviour:
    - Reads the soil moisture sensor once per second (average of 10 samples)
    - Converts the reading to a moisture percentage and shows it on the LCD
    - When the soil is dry (below the threshold), the LCD shows DRY
      and the buzzer gives a short beep with each reading

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. Pin numbers,
  the calibration values, the dry threshold and the LCD address are typical
  or placeholder values, not recovered ones. The calibration values must be
  re-measured with the sensor in dry air and in water before the percentages
  can be trusted.

  Library: "LiquidCrystal I2C" by Frank de Brabander (install from the Library Manager)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------- Pin assignments (adjust to your wiring) ----------
const int SENSOR_PIN = A0;   // Soil moisture sensor analog output
const int BUZZER_PIN = 8;    // Active buzzer

// ---------- Calibration and settings ----------
const int DRY_VALUE = 1023;                    // Placeholder: raw reading in dry air
const int WET_VALUE = 300;                     // Placeholder: raw reading in water
const int DRY_THRESHOLD_PERCENT = 30;          // Below this the soil counts as dry
const unsigned long READ_INTERVAL_MS = 1000;   // Time between readings

// ---------- LCD settings ----------
const uint8_t LCD_ADDRESS = 0x27;   // Common I2C address; some modules use 0x3F
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

unsigned long lastReading = 0;

int readMoisturePercent() {
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(SENSOR_PIN);
    delay(10);
  }
  int raw = total / 10;

  int percent = map(raw, DRY_VALUE, WET_VALUE, 0, 100);   // Dry reads high, wet reads low
  return constrain(percent, 0, 100);
}

void beep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
}

void loop() {
  if (millis() - lastReading >= READ_INTERVAL_MS) {
    lastReading = millis();

    int percent = readMoisturePercent();
    bool dry = (percent < DRY_THRESHOLD_PERCENT);

    char line[17];
    snprintf(line, sizeof(line), "%3d%%  %-8s", percent, dry ? "DRY" : "OK");
    lcd.setCursor(0, 1);
    lcd.print(line);

    Serial.print("Moisture: ");
    Serial.print(percent);
    Serial.println("%");

    if (dry) {
      beep();
    }
  }
}
