// CarloHustle TV - ESP32 Daily Project 03
// Uses WiFi.h and WebServer.h included with the Espressif ESP32 board package.

#include <WebServer.h>
#include <WiFi.h>

const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";
const int ledPin = 2;

WebServer server(80);

void showHomePage() {
  const bool isOn = digitalRead(ledPin) == HIGH;
  const char *state = isOn ? "ON" : "OFF";
  const char *nextAction = isOn ? "off" : "on";

  String page = "<!doctype html><html><head><meta name='viewport' content='width=device-width,initial-scale=1'>";
  page += "<title>CarloHustle ESP32 LED</title></head><body style='font-family:Arial;text-align:center;margin-top:64px'>";
  page += "<h1>ESP32 LED is ";
  page += state;
  page += "</h1><p><a href='/";
  page += nextAction;
  page += "'><button style='font-size:24px;padding:16px 28px'>Turn ";
  page += isOn ? "OFF" : "ON";
  page += "</button></a></p></body></html>";

  server.send(200, "text/html", page);
}

void setLed(bool isOn) {
  digitalWrite(ledPin, isOn ? HIGH : LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }

  Serial.printf("\nOpen http://%s in a browser\n", WiFi.localIP().toString().c_str());

  server.on("/", HTTP_GET, showHomePage);
  server.on("/on", HTTP_GET, []() { setLed(true); });
  server.on("/off", HTTP_GET, []() { setLed(false); });
  server.begin();
}

void loop() {
  server.handleClient();
}
