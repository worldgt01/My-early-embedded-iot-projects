/*
  IoT-Enabled Smart Weighing System
  Board:   ESP32
  Sensors: Load cell + HX711 amplifier
  Cloud:   ThingSpeak (over Wi-Fi)

  Behaviour:
    - Reads the weight from the load cell through the HX711
    - Uploads the reading (in grams) to ThingSpeak field 1 every 20 seconds

  NOTE: This sketch was reconstructed in 2026 from the design of the
  original 2024 project. The original source file was not kept. Pin numbers
  and the calibration factor are typical or placeholder values, not recovered
  ones. The calibration factor must be re-measured with a known weight before
  the readings can be trusted.

  Library: "HX711 Arduino Library" by Bogdan Necula (install from the Library Manager)
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include "HX711.h"

// ---------- Credentials: replace the placeholders. Never commit real ones. ----------
const char* WIFI_SSID          = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD      = "YOUR_WIFI_PASSWORD";
const char* THINGSPEAK_API_KEY = "YOUR_THINGSPEAK_WRITE_API_KEY";

// ---------- Pin assignments (adjust to your wiring) ----------
const int HX711_DOUT_PIN = 16;   // HX711 data
const int HX711_SCK_PIN  = 4;    // HX711 clock

// ---------- Settings ----------
const float CALIBRATION_FACTOR         = 420.0;   // Placeholder: calibrate with a known weight
const unsigned long UPLOAD_INTERVAL_MS = 20000;   // ThingSpeak's free plan allows one update per 15 s

HX711 scale;
unsigned long lastUpload = 0;

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 20000) {
    delay(500);
    Serial.print(".");
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(" connected");
  } else {
    Serial.println(" failed");
  }
}

bool sendToThingSpeak(float grams) {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }
  if (WiFi.status() != WL_CONNECTED) {
    return false;
  }

  HTTPClient http;
  String url = String("http://api.thingspeak.com/update?api_key=") +
               THINGSPEAK_API_KEY + "&field1=" + String(grams, 1);
  http.begin(url);
  int code = http.GET();
  String reply = http.getString();   // ThingSpeak replies with the entry number, or "0" on failure
  http.end();

  return (code == 200 && reply != "0");
}

void setup() {
  Serial.begin(115200);

  scale.begin(HX711_DOUT_PIN, HX711_SCK_PIN);
  scale.set_scale(CALIBRATION_FACTOR);

  Serial.println("Remove all weight from the platform: taring...");
  delay(2000);
  scale.tare();

  connectWiFi();
  Serial.println("System ready.");
}

void loop() {
  float grams = scale.get_units(10);   // Average of 10 readings
  if (grams < 0) {
    grams = 0;
  }

  Serial.print("Weight: ");
  Serial.print(grams, 1);
  Serial.println(" g");

  if (millis() - lastUpload >= UPLOAD_INTERVAL_MS) {
    lastUpload = millis();
    if (sendToThingSpeak(grams)) {
      Serial.println("Uploaded to ThingSpeak");
    } else {
      Serial.println("Upload failed");
    }
  }

  delay(500);
}
