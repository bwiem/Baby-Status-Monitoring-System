# Baby-Status-Monitoring-System
The project addresses the challenge of monitoring a baby's condition in real-time, providing immediate feedback to caregivers without requiring constant physical supervision.
Baby Status Monitoring System
Overview
The Baby Status Monitoring System is a real-time monitoring solution designed to detect and display a baby's status (sleeping, awake, or crying). It uses an ESP32 microcontroller, a potentiometer, LEDs, and an LCD display to provide immediate visual feedback to caregivers.

Features
Real-time detection of baby’s condition:
Sleeping: Green LED ON and LCD displays "Baby is sleeping".
Awake: Yellow LED ON and LCD displays "Baby is awake".
Crying: Red LED ON and LCD displays "Baby is crying".
Simple and cost-effective hardware design.
Modular code for easy customization and enhancements.
System Architecture
The system consists of three main layers:

Perception Layer:
Collects data using a potentiometer to simulate baby behavior.
Processing Layer:
Processes input data using an ESP32 microcontroller.
Output Layer:
Provides feedback via LEDs and an LCD display.
Getting Started
Hardware Requirements
ESP32 microcontroller
Potentiometer
LEDs (Green, Yellow, Red)
LCD Display (16x2, I2C)
Breadboard and jumper wires
Software Requirements
Arduino IDE (with ESP32 board manager installed)
Required libraries:
LiquidCrystal_I2C
Setup Instructions
Clone the Repository:

Navigate to the code/ directory and open BabyStatusMonitor.ino in the Arduino IDE.
Upload the Code:
Connect your ESP32 to your computer and upload the code.
Assemble the Circuit:
Follow the wiring instructions provided in the documents/Baby_Status_User_Guide.docx.
Operation
Power on the system.
Adjust the potentiometer to simulate different baby conditions:
Low range (0–400): Baby sleeping.
Medium range (401–2500): Baby awake.
High range (2501–4095): Baby crying.
Future Improvements
Add a buzzer for sound alerts.
Integrate mobile app support for remote monitoring.
Implement SD card logging for activity tracking.
