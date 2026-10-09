/*
  IoT-Based Remote Lighting Control System
  Board:   ESP32
  Cloud:   Blynk IoT (blynk.cloud)
  Output:  Relay module switching a mains lamp

  Behaviour:
    - The ESP32 connects to Wi-Fi and to the Blynk cloud
    - A Switch widget in the Blynk phone app or web dashboard (virtual pin V0) turns the lamp ON or OFF
    - Because the command goes through the Blynk cloud, the lamp can be
      controlled from anywhere with an internet connection

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. The relay pin,
  the virtual pin (V0) and the template details are typical or placeholder
  values, not recovered ones.

  Library: "Blynk" by Volodymyr Shymanskyy (install from the Library Manager)
*/

// ---------- Blynk template details: replace the placeholders. Never commit real ones. ----------
#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Remote Lighting Control"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// ---------- Wi-Fi credentials: replace the placeholders. Never commit real ones. ----------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ---------- Pin assignment (adjust to your wiring) ----------
const int RELAY_PIN = 26;

// ---------- Settings ----------
const bool RELAY_ACTIVE_LOW = true;   // Most relay modules switch ON when the pin goes LOW

void setRelay(bool on) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
  }
}

// Runs whenever the Switch widget on virtual pin V0 changes in the Blynk app
BLYNK_WRITE(V0) {
  int state = param.asInt();   // 1 = ON, 0 = OFF
  setRelay(state == 1);
  Serial.println(state == 1 ? "Lamp ON" : "Lamp OFF");
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  setRelay(false);   // Start with the lamp off

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
