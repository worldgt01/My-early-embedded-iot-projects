# 🔢 Keypad and LCD-Based Embedded Interface System

📅 **Developed:** 2024
🔧 **Category:** Embedded Systems / Interfacing
📌 **Status:** Completed Prototype

---

## 📖 Overview

This was one of my early hands-on embedded systems projects. The system reads input from a keypad and shows each key pressed on an LCD screen.

An ESP32 scans a matrix keypad to detect which key is pressed, and sends it to an I2C LCD, where it appears on the display.

---

## ⚙️ How It Works

Key pressed → ESP32 scans the keypad matrix → Key identified → Sent to the LCD over I2C → Key appears on the screen

---

## 🔧 Components Used

- ESP32
- Matrix keypad
- I2C LCD display
- Breadboard and jumper wires

---





---

## 🎥 Demonstration

A short demonstration of the system showing the keys pressed on the LCD.



https://github.com/user-attachments/assets/e588db20-e4ef-4bee-8cc6-2ce83e4ed535



---

## 💻 Code

The Arduino sketch is in [`code/keypad_lcd`](./code/keypad_lcd/keypad_lcd.ino).

> **Note:** The original 2024 source file was not kept. This sketch was reconstructed in 2026 from the project's design and behaviour, so pin numbers and the I2C address are typical values, not recovered ones.

---

## 📚 What I Learned

- Interfacing a matrix keypad with a microcontroller
- Detecting key presses by scanning rows and columns
- Communicating with an LCD over I2C
- Displaying user input in real time on a screen
- Hardware integration and troubleshooting

---

### 🚀 Early Engineering Journey

This project was part of my early exploration of embedded systems in 2024. It gave me practical experience handling user input and displaying output on an embedded device, a foundation for my later work in IoT and intelligent embedded systems.

*Originally developed in 2024. Documented and uploaded in 2026.*
