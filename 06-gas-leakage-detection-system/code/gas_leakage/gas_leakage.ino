/*
  Gas Leakage Detection System
  Board:   ESP32
  Sensor:  MQ-2 gas sensor (analog output)
  Output:  I2C LCD (16x2)

  Behaviour:
    - Waits for the MQ-2 sensor to warm up after power-up
    - Reads the sensor once per second (average of 10 samples)
    - Shows the gas level as a percentage on the LCD: the value rises when
      gas is near the sensor and falls again when the gas is removed

  Wiring caution: the MQ-2 analog output can reach 5 V, but ESP32 pins only
  tolerate 3.3 V. Use a voltage divider between the sensor output and the
  ESP32 input pin.

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. Pin numbers,
  the LCD address and the LCD wording are typical or placeholder values, not
  recovered ones, and this reconstruction has not been tested on hardware.
  The percentage is a relative gas level, not a calibrated concentration in ppm.

  Library: "LiquidCrystal I2C" by Frank de Brabander (install from the Library Manager)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------- Pin assignments (adjust to your wiring) ----------
const int GAS_SENSOR_PIN = 34;   // MQ-2 analog output (through a voltage divider)

// ---------- Settings ----------
const int ADC_MAX                    = 4095;     // ESP32 ADC is 12-bit
const unsigned long WARMUP_MS        = 20000;    // MQ-2 needs time to heat up before readings settle
const unsigned long READ_INTERVAL_MS = 1000;     // Time between readings

// ---------- LCD settings ----------
const uint8_t LCD_ADDRESS = 0x27;   // Common I2C address; some modules use 0x3F
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

unsigned long lastReading = 0;

int readGasPercent() {
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(GAS_SENSOR_PIN);
    delay(10);
  }
  int raw = total / 10;

  Serial.print("Raw ADC: ");
  Serial.println(raw);

  return (int)((long)raw * 100 / ADC_MAX);
}

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);   // ESP32 default I2C pins: SDA = 21, SCL = 22
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("MQ-2 warming up");
  delay(WARMUP_MS);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas level:");
}

void loop() {
  if (millis() - lastReading >= READ_INTERVAL_MS) {
    lastReading = millis();

    int percent = readGasPercent();

    char line[17];
    snprintf(line, sizeof(line), "%3d%%            ", percent);
    lcd.setCursor(0, 1);
    lcd.print(line);

    Serial.print("Gas level: ");
    Serial.print(percent);
    Serial.println("%");
  }
}
