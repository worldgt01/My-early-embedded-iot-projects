/*
  Keypad and LCD-Based Embedded Interface System
  Board:   ESP32
  Inputs:  Matrix membrane keypad
  Outputs: I2C LCD (16x2)

  Behaviour:
    - Each key pressed on the keypad is shown on the second line of the LCD
    - When the line is full (16 characters), it clears and starts again
    - Each key press is also printed to the Serial Monitor

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. Pin numbers,
  the I2C address (0x27) and the 4x4 key layout are typical values, not
  recovered ones, so adjust them to match your hardware.

  Libraries (install from the Library Manager):
    - "Keypad" by Mark Stanley and Alexander Brevig
    - "LiquidCrystal I2C" by Frank de Brabander
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ---------- LCD settings ----------
const uint8_t LCD_ADDRESS = 0x27;   // Common I2C address; some modules use 0x3F
const uint8_t LCD_COLUMNS = 16;
const uint8_t LCD_ROWS    = 2;

// ---------- Keypad settings (adjust to your wiring) ----------
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[KEYPAD_ROWS] = {19, 18, 5, 17};
byte colPins[KEYPAD_COLS] = {16, 4, 32, 33};

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

uint8_t cursorColumn = 0;

void clearInputLine() {
  lcd.setCursor(0, 1);
  for (uint8_t i = 0; i < LCD_COLUMNS; i++) {
    lcd.print(' ');
  }
  cursorColumn = 0;
}

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);   // ESP32 default I2C pins: SDA = 21, SCL = 22
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Press a key:");
  clearInputLine();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (cursorColumn >= LCD_COLUMNS) {
      clearInputLine();
    }

    lcd.setCursor(cursorColumn, 1);
    lcd.print(key);
    cursorColumn++;

    Serial.print("Key pressed: ");
    Serial.println(key);
  }
}
