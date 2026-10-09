# 💡 Automatic Motion-Activated Lighting & Alert System

📅 **Developed:** 2024
🔧 **Category:** Embedded Systems / Automation
📌 **Status:** Completed Prototype

---

## 📖 Overview

This was one of my early hands-on embedded systems projects. The system turns a light on automatically when a person passes by, and sounds a buzzer as an audible alert.

A PIR motion sensor detects movement, an Arduino Nano processes the signal, and a relay module switches a mains lamp on. A buzzer adds sound feedback when motion is detected.

---

## ⚙️ How It Works

Person moves → PIR sensor detects → Arduino Nano processes → Relay switches lamp ON → Buzzer sounds

The light stayed on for about 10 seconds after the last detected motion, then switched off automatically.

---

## 🔧 Components Used

- Arduino Nano
- PIR motion sensor
- Relay module
- Buzzer
- Mains lamp
- Breadboard and jumper wires

---

## 📸 Project Photos

Some of the components I worked with during my early embedded systems experiments, including the Arduino Nano, relay module and PIR sensor.




---
<img width="1080" height="810" alt="IMG-20241009-WA0015" src="https://github.com/user-attachments/assets/aaa79efd-74d6-46cd-84f2-9db02d0ca719" />
<img width="1080" height="810" alt="IMG-20241009-WA0014" src="https://github.com/user-attachments/assets/c7fc8ea9-fb7d-4e6b-97f3-b195b73bc34c" />
<img width="810" height="1080" alt="IMG-20241009-WA0013" src="https://github.com/user-attachments/assets/e15465f1-fdd9-458e-8d49-08e247440ba2" />
<img width="810" height="1080" alt="IMG-20241009-WA0012" src="https://github.com/user-attachments/assets/4b415ae9-8346-42aa-bf72-8412fcf66b11" />


---

## 🎥 Demonstration

A short demonstration of the system switching the lamp on when motion is detected.


https://github.com/user-attachments/assets/90deee1a-fd9d-4031-8fa2-dc0cde1a39f5



https://github.com/user-attachments/assets/29ec3711-73ba-457f-a784-5f76a605a85a

## 💻 Code

The Arduino sketch is in [`code/motion_lighting_alert`](./code/motion_lighting_alert/motion_lighting_alert.ino).

> **Note:** The original 2024 source file was not kept. This sketch was reconstructed in 2026 from the project's design and behaviour, so pin numbers are typical values, not recovered ones.

---

## 📚 What I Learned

- Interfacing a PIR motion sensor with a microcontroller
- Driving a relay module from an Arduino
- Switching a mains-powered load safely through a relay
- Adding audible feedback with a buzzer
- Turning a sensor reading into an automatic action

---

### 🚀 Early Engineering Journey

This project was part of my early exploration of embedded systems in 2024. It gave me practical experience turning sensor input into real-world control, a foundation for my later work in IoT and intelligent embedded systems.

*Originally developed in 2024. Documented and uploaded in 2026.*
