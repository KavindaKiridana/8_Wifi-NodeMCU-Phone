# 🚀 ESP8266 WiFi LED Control

A simple web server running on ESP8266 that lets you control an LED through a mobile-friendly web interface.

## 📂 Hardware Requirements

- ESP8266 board (NodeMCU)
- LED (optional - built-in LED will work)
- 220Ω resistor (if using external LED)
- Micro USB cable

## 📂 Software Requirements

- PlatformIO IDE
- ESP8266 board support
- WiFi network

## 📂 Setup

1. Clone this repository
2. Open in PlatformIO
3. Edit `main.cpp`:
   - Replace `YOUR_WIFI_NAME` with your WiFi name
   - Replace `YOUR_WIFI_PASSWORD` with your WiFi password
4. Upload to your ESP8266
5. Open Serial Monitor to get the IP address
6. Access the web interface by entering the IP address in any browser

## 📂 Files

- `main.cpp`: Contains the web server and LED control code
- `platformio.ini`: PlatformIO configuration for ESP8266

## 📂 Circuit

Connect LED positive to GPIO2 (D4) and negative to GND through a 220Ω resistor. Or use the built-in LED on GPIO2.
