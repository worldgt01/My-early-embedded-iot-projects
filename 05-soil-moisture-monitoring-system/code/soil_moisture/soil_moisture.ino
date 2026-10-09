/*
  Smart Soil Moisture Monitoring System
  Board:   Arduino Uno
  Sensor:  Analog soil moisture sensor
  Outputs: I2C LCD (16x2) and a buzzer

  Behaviour (three states):
    - NEEDS WATER : moisture is too low  -> the buzzer keeps beeping
    - OVERFLOW    : moisture is too high -> the buzzer keeps beeping
    - PERFECT     : moisture is in the right range -> the buzzer stays silent
    The moisture percentage and the current state are shown on the LCD.

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. Pin numbers,
  the calibration values, the two thresholds, the LCD address and the LCD
  wording are typical or placeholder values, not recovered ones. The
  calibration values must be re-measured with the sensor in dry air and in
  water before the percentages can be trusted.

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
const int NEEDS_WATER_BELOW_PERCENT = 30;      // Below this: needs water
const int OVERFLOW_ABOVE_PERCENT    = 80;      // Above this: overflow
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
  lcd.print("Moisture level:");
}

void loop() {
  if (millis() - lastReading >= READ_INTERVAL_MS) {
    lastReading = millis();

    int percent = readMoisturePercent();

    const char* state;
    bool alarm;
    if (percent < NEEDS_WATER_BELOW_PERCENT) {
      state = "NEEDS WATER";
      alarm = true;
    } else if (percent > OVERFLOW_ABOVE_PERCENT) {
      state = "OVERFLOW";
      alarm = true;
    } else {
      state = "PERFECT";
      alarm = false;
    }

    char line[17];
    snprintf(line, sizeof(line), "%3d%% %-11s", percent, state);
    lcd.setCursor(0, 1);
    lcd.print(line);

    Serial.print("Moisture: ");
    Serial.print(percent);
    Serial.print("% - ");
    Serial.println(state);

    if (alarm) {
      beep();   // Repeats on every reading while the alarm state lasts
    }
  }
}
