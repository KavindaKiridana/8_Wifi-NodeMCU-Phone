#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi credentials
const char *ssid = "SLT-Fiber";
const char *password = "0112846034";

ESP8266WebServer server(80);

// D4 is GPIO2, which has an onboard LED on many ESP8266 boards
const int LED_PIN = 2;

void setup()
{
  // Serial.begin(115200);
  Serial.begin(9600);

  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup web server routes
  server.on("/", HTTP_GET, []()
            {
    String html = R"(
      <!DOCTYPE html>
      <html>
      <head>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'>
        <style>
          body { text-align: center; font-family: Arial; margin-top: 50px; }
          button { 
            padding: 20px 40px; 
            font-size: 20px; 
            margin: 10px; 
            border-radius: 5px;
            border: none;
            cursor: pointer;
          }
          .on { background: #4CAF50; color: white; }
          .off { background: #f44336; color: white; }
        </style>
      </head>
      <body>
        <h1>ESP8266 LED Control</h1>
        <button class='off' onclick='fetch("/on")'>Turn OFF</button>
        <button class='on' onclick='fetch("/off")'>Turn ON</button>
      </body>
      </html>
    )";
    server.send(200, "text/html", html); });

  server.on("/on", HTTP_GET, []()
            {
    digitalWrite(LED_PIN, HIGH);
    server.send(200, "text/plain", "LED ON"); });

  server.on("/off", HTTP_GET, []()
            {
    digitalWrite(LED_PIN, LOW);
    server.send(200, "text/plain", "LED OFF"); });

  server.begin();
}

void loop()
{
  server.handleClient();
}