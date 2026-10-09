# 🌱 Smart Soil Moisture Monitoring System

📅 **Developed:** 2024
🔧 **Category:** Embedded Systems / Sensing
📌 **Status:** Completed Prototype

---

## 📖 Overview

This was one of my early hands-on embedded systems projects. The system measures moisture, shows the level on an LCD, and uses a buzzer to tell the user when the level is wrong.

A soil moisture sensor is read by an Arduino Uno, which converts the reading into a moisture level and decides which of three states the system is in. The level and its state are shown on the LCD.

---

## ⚙️ How It Works

Soil moisture sensor → Arduino Uno reads the signal → Converted to a moisture level → Compared against two limits → State shown on the LCD

I designed it to respond in three ways:

| State | What the system does |
|---|---|
| **Needs water** (level too low) | The LCD shows the state and the buzzer keeps beeping |
| **Overflow** (level too high) | The LCD shows the state and the buzzer keeps beeping |
| **Perfect level** | The LCD shows the state and the buzzer stays silent |

---

## 🧪 Testing

The system was first tested with the sensor placed in water, to check that the readings and the LCD display responded and that each of the three states was triggered correctly. It was later tested in soil as well.

The demonstration video below shows the water test.

---

## 🔧 Components Used

- Arduino Uno
- Soil moisture sensor
- LCD display
- Buzzer
- Breadboard and jumper wires

---

## 📸 Project Photos build up

<img width="3000" height="4000" alt="20240926_174707" src="https://github.com/user-attachments/assets/1d0b513f-e37c-49b4-83e6-74c199a8b55c" />
<img width="3000" height="4000" alt="20240926_174630" src="https://github.com/user-attachments/assets/48ac0228-5677-43b8-9d73-b2b379f11de2" />


---

## 🎥 Demonstration

A short demonstration of the system showing the moisture level and its state on the LCD. In this video, the sensor is being tested in water.



https://github.com/user-attachments/assets/0f2eb166-2774-49fe-9d0e-943dc5b896b8



---

## 💻 Code

The Arduino sketch is in [`code/soil_moisture`](./code/soil_moisture/soil_moisture.ino).

> **Note:** The original 2024 source file was not kept. This sketch was reconstructed in 2026 from the project's design and behaviour, so pin numbers, calibration values, the two limits and the LCD wording are typical or placeholder values, not recovered ones.

---

## 📚 What I Learned

- Reading an analog sensor with a microcontroller
- Converting a raw sensor reading into a meaningful moisture level
- Using two limits to split a reading into three states
- Displaying live measurements and status on an LCD
- Triggering an audible alert from a sensor reading
- Hardware integration and troubleshooting

---

### 🚀 Early Engineering Journey

This project was part of my early exploration of embedded systems in 2024. It gave me practical experience turning a real-world measurement into a readable display and an alert, a foundation for my later work in IoT and sensing systems.

*Originally developed in 2024. Documented and uploaded in 2026.*
