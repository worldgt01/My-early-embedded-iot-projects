# 📱 IoT-Based Remote Lighting Control System

📅 **Developed:** 2024
🔧 **Category:** Embedded Systems / IoT
📌 **Status:** Completed Prototype

---

## 📖 Overview

This was one of my early IoT projects, and a really fun 😁 one to build. The system lets me switch a light on and off remotely, from my phone or my laptop, from anywhere with an internet connection.

An ESP32 connects to Wi-Fi and to the Blynk IoT cloud. When I flip a switch in the Blynk phone app or in the Blynk web dashboard on my laptop, the command reaches the ESP32, which drives a relay that switches the light.

---

## ⚙️ How It Works

Phone or laptop → Blynk cloud → ESP32 over Wi-Fi → Relay → Light ON/OFF

---

## 🔧 Components Used

- ESP32
- Relay module
- Mains lamp
- Mirror frame lighting
- Wi-Fi connectivity
- Blynk IoT platform (phone app and web dashboard)
- Breadboard and jumper wires

---

## 💡 Where I Used It

- **A mains lamp.** I switched it on and off remotely through the relay.
- **Mirror frame lighting.** I moved the same relay setup to the lighting around a mirror frame and controlled it the same way.

I controlled both from my phone and from my laptop.

**My role:** hardware assembly, programming and testing, all done by me.

---

---

## 🎥 Demonstration



https://github.com/user-attachments/assets/512124f0-6a56-4f33-99ed-982572774225



https://github.com/user-attachments/assets/3237e5ec-f424-4483-a9dc-62e6e46f807e



---

## 💻 Code

The Arduino sketch is in [`code/remote_lighting`](./code/remote_lighting/remote_lighting.ino).

> **Note:** The original 2024 source file was not kept. This sketch was reconstructed in 2026 from the project's design and behaviour, so the relay pin and Blynk template details are typical or placeholder values, not recovered ones.

---

## 📚 What I Learned

- Connecting an ESP32 to Wi-Fi and to an IoT cloud platform
- Using the Blynk IoT app and web dashboard to control hardware remotely
- Driving a relay module from a microcontroller
- Switching mains-powered loads safely through a relay
- Controlling the same hardware from more than one device

---

### 🚀 Early Engineering Journey

This project was part of my early exploration of IoT in 2024. It showed me how a phone or laptop can control a physical device from anywhere, which is the foundation for my later work in connected and intelligent embedded systems.

*Originally developed in 2024. Documented and uploaded in 2026.*
