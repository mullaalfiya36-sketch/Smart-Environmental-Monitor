# 🌡️ Smart Environmental Monitor

An ESP32-based environmental monitoring project that measures **temperature and humidity** using a DHT22 sensor and displays the readings on a **16×2 I2C LCD**.

This project was developed as a hands-on IoT/embedded systems project to understand sensor interfacing, I2C communication, error handling, and non-blocking timing using `millis()`.

## 🎯 Project Description

The Smart Environmental Monitor continuously reads temperature and humidity from a DHT22 sensor connected to an ESP32.

The measured values are:

* Displayed on a 16×2 I2C LCD
* Printed to the Serial Monitor
* Updated every 2 seconds
* Checked for invalid sensor readings

Instead of repeatedly using `delay()` inside the main loop, the project uses **`millis()` for non-blocking timing**, allowing the ESP32 to remain available for other tasks.

## 🔧 Components Used

* ESP32 development board
* DHT22 temperature and humidity sensor
* 16×2 I2C LCD
* Breadboard
* Jumper wires
* Resistor for DHT22 data line, if required by the physical sensor setup

## 🔌 Wiring

### DHT22 → ESP32

| DHT22 Pin | ESP32         |
| --------- | ------------- |
| VCC       | 3.3V          |
| DATA      | GPIO 4        |
| NC        | Not connected |
| GND       | GND           |

### I2C LCD → ESP32

| LCD Pin | ESP32   |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| SDA     | GPIO 21 |
| SCL     | GPIO 22 |

## ⚙️ How It Works

1. The ESP32 initializes the DHT22 sensor and I2C LCD.
2. The DHT22 measures temperature and humidity.
3. The ESP32 checks whether 2 seconds have passed using `millis()`.
4. The sensor values are read.
5. The values are displayed on the LCD.
6. The same values are sent to the Serial Monitor.
7. If the sensor reading fails, an error message is displayed.

## ⭐ Features

* 🌡️ Temperature monitoring
* 💧 Humidity monitoring
* 📟 Real-time LCD display
* 🖥️ Serial Monitor output
* ⏱️ Non-blocking timing using `millis()`
* ⚠️ DHT22 sensor error detection
* 🔌 I2C communication with LCD
* 📡 ESP32-based IoT hardware platform

## 🧠 Concepts Learned

This project helped me understand:

* ESP32 GPIO interfacing
* DHT22 sensor interfacing
* I2C communication
* LCD interfacing
* `millis()`-based non-blocking programming
* Sensor error handling
* Serial communication and baud rates
* Basic IoT environmental monitoring

## 🛠️ Future Improvements

Possible future improvements include:

* Adding temperature and humidity threshold alerts
* Adding an LED or buzzer for abnormal conditions
* Sending sensor data to an IoT/cloud dashboard
* Adding Wi-Fi-based remote monitoring
* Storing historical sensor readings
* Adding configurable sensor calibration

## 📁 Project Structure

```text
Smart-Environmental-Monitor/
│
├── smart_environmental_monitor.ino
└── README.md
```

## 🚀 Project Status

**Completed — Basic ESP32 environmental monitoring system working successfully.**

The project was initially tested through simulation and developed to demonstrate practical embedded and IoT concepts.
