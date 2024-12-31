# 8_Wifi NodeMCU Phone

Turn on/off NodeMCU's built-in LED bulb by phone via connecting to Wi-Fi.

Programming:

Copy the code above into src/main.cpp
Edit the WiFi settings:

Change YOUR_WIFI_NAME to your WiFi network name
Change YOUR_WIFI_PASSWORD to your WiFi password

Upload the code to your ESP8266

Testing:

Open Serial Monitor at 115200 baud
The ESP8266 will print its IP address after connecting
On your iPhone:

Connect to the same WiFi network as the ESP8266
Open Safari
Enter the IP address shown in Serial Monitor
You should see two buttons to control the LED

Common Issues & Solutions:

If it won't connect to WiFi:

Double-check WiFi name and password
Make sure you're using 2.4GHz WiFi (ESP8266 doesn't support 5GHz)

If the web page won't load:

Verify your iPhone is on the same WiFi network
Try refreshing the page
Check the IP address in Serial Monitor
