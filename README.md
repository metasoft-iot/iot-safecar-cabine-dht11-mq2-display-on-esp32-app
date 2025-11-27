# IoT Safecar Cabine DHT22 MQ2 GPS LCD ON ESP32 DEVKIT V1 APP

**Version**: 0.1
**Author**: Metasoft Development Team
**Date**: November 27, 2025

## Overview

<p align="justify">
This project demonstrates the usage of the Modest IoT Nano-framework (C++ Edition) v0.1 by implementing a `SmartCabineDevice`. This device monitors air quality using an MQ2 gas sensor, environmental conditions with a DHT22 sensor, and tracks location using a GPS module. It features an LCD display for real-time status updates and activates a visual LED alert when hazardous gas levels are detected, showcasing the framework’s modular and event-driven architecture.
</p>

## Prerequisites
- **Hardware**: ESP32 development board, DHT22 sensor, MQ2 gas sensor, NEO-6M GPS module, LCD 16x2 (I2C interface), an LED with a 220Ω resistor.
- **Software**: Arduino IDE with ESP32 support, or Wokwi for simulation.
- **Dependency**: Modest IoT Nano-framework (C++ Edition) v0.1.

## Features
- **Air Quality Monitoring**: Continuously measures gas concentration levels using an MQ2 sensor.
- **Environment Monitoring**: Reads temperature and humidity data from a DHT22 sensor.
- **Location Tracking**: Interfaces with a GPS module to provide real-time geolocation.
- **Visual Alert System**: Activates an LED indicator when gas levels exceed safe thresholds.
- **Status Display**: Cyclically displays sensor data and status on an I2C LCD screen.
- **Modular Design**: Orchestrates custom components (`GasSensor`, `EnvironmentSensor`, `GpsService`, `DisplayService`) through a central `SmartCabineDevice` class.
- **Simulation Support**: Ready for simulation on Wokwi with integrated sensor models.

## Installation

<p align="justify">
1. <b>Framework</b>: This project already includes the necessary framework files.
</p>


<p align="justify">
2. <b>Project Structure</b>: The project follows a flat structure, keeping all source and header files in the root directory for simplicity and compatibility with the Arduino IDE.
</p>

```planetext
smart-cabine-embedded-app/
├── SmartCabineDevice.h
├── SmartCabineDevice.cpp
├── EnvironmentSensor.h
├── EnvironmentSensor.cpp
├── GasSensor.h
├── GasSensor.cpp
├── GpsService.h
├── GpsService.cpp
├── DisplayService.h
├── DisplayService.cpp
├── Led.h
├── Led.cpp
├── ModestIoT.h
├── Device.h
├── Device.cpp
├── Sensor.h
├── Sensor.cpp
├── Actuator.h
├── Actuator.cpp
├── EventHandler.h
├── CommandHandler.h
├── sketch.ino
├── diagram.json
├── libraries.txt
└── README.md
```

