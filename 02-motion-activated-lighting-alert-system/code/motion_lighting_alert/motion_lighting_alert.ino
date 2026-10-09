/*
  Automatic Motion-Activated Lighting & Alert System
  Board:   Arduino Nano
  Inputs:  PIR motion sensor
  Outputs: Relay module (switches a mains lamp), buzzer

  Behaviour:
    - Motion detected    -> relay switches the lamp ON and the buzzer beeps twice
    - Motion keeps       -> the 10-second timer restarts each time motion is seen
    - No motion for 10 s -> relay switches the lamp OFF

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. Pin numbers
  are typical choices, not recovered values, so adjust them to match your wiring.
*/

// ---------- Pin assignments (adjust to your wiring) ----------
const int PIR_PIN    = 2;   // PIR sensor output
const int RELAY_PIN  = 7;   // Relay module input
const int BUZZER_PIN = 8;   // Active buzzer

// ---------- Settings ----------
const unsigned long LIGHT_ON_TIME_MS = 10000;  // Lamp stays on 10 s after last motion
const unsigned long PIR_WARMUP_MS    = 30000;  // PIR sensors need time to settle after power-up
const bool RELAY_ACTIVE_LOW          = true;   // Most relay modules switch ON when the pin goes LOW

// ---------- State ----------
bool lightOn = false;
unsigned long lastMotionTime = 0;

void setRelay(bool on) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
  }
}

void beep(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(150);
    digitalWrite(BUZZER_PIN, LOW);
    delay(150);
  }
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  setRelay(false);                 // Start with the lamp off
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Warming up PIR sensor...");
  delay(PIR_WARMUP_MS);
  Serial.println("System ready.");
}

void loop() {
  unsigned long now = millis();

  if (digitalRead(PIR_PIN) == HIGH) {
    lastMotionTime = now;          // Restart the 10-second timer on every detection

    if (!lightOn) {
      lightOn = true;
      setRelay(true);
      beep(2);
      Serial.println("Motion detected: lamp ON");
    }
  }

  if (lightOn && (now - lastMotionTime >= LIGHT_ON_TIME_MS)) {
    lightOn = false;
    setRelay(false);
    Serial.println("No motion for 10 s: lamp OFF");
  }
}
