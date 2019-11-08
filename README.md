[![author](https://img.shields.io/badge/Author-Mukadam%20Uzair-green.svg)](http://theuzitech.com/)
[![author](https://img.shields.io/badge/Author-Patel%20Mubeen-red.svg)](https://mubeenpatel99.github.io/mubeenpatel.github.io/)
[![author](https://img.shields.io/badge/Author-Bhayani%20Arish-blue.svg)](https://www.agentsicarrio.com/)
[![author](https://img.shields.io/badge/Author-Shaikh%20Hasnain-orange.svg)](https://www.hasnainshaikh404.com/)
[![made-with-Arduino](https://img.shields.io/badge/Made%20with-Arduino-yellow.svg)](https://www.arduino.cc/)

# Automatic-Smart-Irrigation-System
A system that estimates and measures the moisture of soil in order to operate an irrigation system, restoring water as needed while minimizing excess water use and help the user to monitor the data for further use.

## Objective
* To design an automatic irrigation system thereby saving time & power for the farmer.
*	To design a proto-type and test it on small scale so that we can create an effective solution for the problems on large scale.
*	Eliminating human interaction as much as possible in the process.
*	Providing the plants with water only when they require.
*	Providing a more modular system for easy upgrades.
*	Easy monitoring from anywhere in the world.

## Hardware Requirements
* Arduino Uno.
* NodeMCU.
* DS 1307 RTC.
* Soil Moisture Sensor.
* Water Depth Sensor.
* 5v Single channel Relay.
* 16x2 LCD.

## Software Requirements
* Arduino IDE.
* Thingspeak **READ** and **WRITE _API keys_**.

## Connections

### Connecting the RTC to Arduino UNO.
* Connect module VCC to Arduino’s 5v out pin.
* Connect module GND to Arduino’s GND.
* Connect module SDA and SCL pins to Arduino SDA and SCL pins.

### Connecting the LCD with Arduino UNO.
* Pin 1 to GND.
* Pin 2 to 5v.
* Pin 3 to pin 10.
* Pin 4 to pin 12.
* Pin 5 to GND.
* Pin 6 to pin 11.
* Pin 11 to pin 5.
* Pin 12 to pin 4.
* Pin 13 to pin 3.
* Pin 14 to pin 2.
* Pin 15 to pin 5v.
* Pin 16 to pin GND.

### Connecting Soil Moisture Sensor to Arduino UNO.
* Connect sensor VCC to Arduino’s 5v pin.
* Connect sensor GND to Arduino’s GND pin.
* Connect sensor analog pin to Arduino A0 pin.

### Connecting the water depth sensor to Arduino UNO.
* Connect sensor VCC to Arduino’s 5v pin.
* Connect sensor GND to Arduino’s GND pin.
* Connect sensor analog pin to Arduino A1 pin.

### Connecting the Relay module to Arduino UNO.
* Connect sensor VCC to Arduino’s 5v pin.
* Connect sensor GND to Arduino’s GND pin.
* Connect sensor IN pin to Arduino 8 pin.

### Connecting Pump to Relay module.
* Connect pump GND to Arduino GND pin.
* Connect pump VCC to Relay.

### Connecting NodeMCU to Arduino.
* Connect NodeMCU Vin to Arduino’s 5v out pin.
* Connect NodeMCU GND to Arduino’s GND pin.
* Connect NodeMCU D1 to Arduino’s pin 0.
* Connect NodeMCU D2 to Arduino’s pin 1.
* Connect NodeMCU D3 to Arduino’s pin 7.

## Configuring the Setup.
* Set the time for watering plants in morning.
* Set minimum soil moisture level depending on plant.
* Adjust the level for water depth sensor.

## Configuring NodeMCU.
* Set the Wi-Fi name to connect to.
* Enter the password of the Wi-Fi network.
* Enter the ThingSpeak Channel ID and API_Key.

