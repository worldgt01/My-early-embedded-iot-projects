# 💨 Gas Leakage Detection System

📅 **Developed:** 2024
🔧 **Category:** Embedded Systems / Sensing
📌 **Status:** Completed Prototype

---

## 📖 Overview

This was one of my early hands-on embedded systems projects. The system detects gas near a sensor and shows the gas level on an LCD screen.

An MQ-2 gas sensor is read by an ESP32, which converts the sensor signal into a gas level and displays it on the LCD in real time.

---

## ⚙️ How It Works

MQ-2 gas sensor → ESP32 reads the analog signal → Converted to a gas level → Shown on the LCD

When gas reaches the sensor, the reading goes up. When the gas is removed, the reading falls again.

---

## 🧪 Testing

After building the circuit, I tested it by holding a gas lighter close to the sensor, to see whether it would detect the gas and show the change on the LCD.

The value on the screen increased as the gas reached the sensor, and it dropped again once the gas was removed. The test was successful.

---

## 🔧 Components Used

- ESP32
- MQ-2 gas sensor
- LCD display
- Jumper wires

---


---

## 🎥 Demonstration

A short demonstration from the original 2024 build: the gas level on the LCD rises when gas is brought close to the sensor and falls when it is removed.




https://github.com/user-attachments/assets/1d5b3929-89ac-4061-be8b-6a4e8fd02b4c




---

## 💻 Code

The Arduino sketch is in [`code/gas_leakage`](./code/gas_leakage/gas_leakage.ino).

> **Note:** The original 2024 source file was not kept. This sketch was reconstructed in 2026 from the project's design and behaviour, so pin numbers and the LCD address are typical values, not recovered ones. The reconstruction has not been tested on hardware.

---

## 📚 What I Learned

- Interfacing an MQ-2 gas sensor with a microcontroller
- Reading an analog sensor signal with an ESP32
- Displaying live sensor readings on an LCD
- Testing a sensor's response by introducing and removing a gas source
- Hardware integration and troubleshooting

---

### 🚀 Early Engineering Journey

This project was part of my early exploration of embedded systems in 2024. It gave me practical experience reading a real-world sensor and showing the result on a display, a foundation for my later work in IoT and sensing systems.

*Originally developed in 2024. Documented and uploaded in 2026.*
