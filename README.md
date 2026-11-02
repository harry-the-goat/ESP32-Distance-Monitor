# ESP32 Distance Monitor

An ESP32-based distance monitoring system using an HC-SR04 ultrasonic sensor, OLED display, RGB LED and buzzer.

# Components Used

* ESP32 Development Board
* HC-SR04 Ultrasonic Sensor
* 0.96-inch OLED Display (128×64)
* RGB LED
* Buzzer
* Jumper Wires

# Features

* Measures distance using an ultrasonic sensor.
* Displays real-time distance readings on an OLED.
* RGB LED indicates the distance status.
* Buzzer activates when an object comes within 10 cm.

# Operating Conditions

| Distance        | Status  | LED Indication |
| --------------- | ------- | -------------- |
| Less than 10 cm | DANGER  | Red + Buzzer   |
| 10–20 cm        | CAUTION | Yellow    |
| 20 cm or more   | SAFE    | Green          |

# Pin Connections

| Component          | ESP32 Pin  |
| ------------------ | ---------- |
| OLED VDD           | 3V3        |
| OLED SDA           | GPIO 22    |
| OLED SCL           | GPIO 21    |
| OLED GND           | GND        |
| RGB LED Red        | GPIO 2     |
| RGB LED Green      | GPIO 4     |
| RGB LED Blue       | GPIO 5     |
| RGB Common Cathode | GND        |
| HC-SR04 VCC        | 5V         |
| HC-SR04 Trig       | GPIO 15    |
| HC-SR04 Echo       | GPIO 16    |
| HC-SR04 GND        | GND        |
| Buzzer Anode       | GPIO 18    |
| Buzzer Cathode     | GND        |

# Libraries Required

* Adafruit GFX Library
* Adafruit SSD1306 Library

# Working

The HC-SR04 sensor measures the distance between an object and the sensor. The ESP32 processes the readings and displays them on the OLED. The RGB LED indicates the safety status, while the buzzer provides an alert when an object gets too close.

# Author

Hardik Jain

Electrical Engineering Student | NSUT

