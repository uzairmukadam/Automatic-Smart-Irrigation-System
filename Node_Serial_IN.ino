#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "wifi-username"; // your wifi name
const char* password = "wifi-password"; // your wifi password

WiFiClient clients;

unsigned long ChannelNo = ; your channel key
const char * API_Key = "02BHJL8138761"; //your Personal API Key.

void setup() {
  Serial.begin(9600);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.println();
  delay(10);
  ThingSpeak.begin(clients);
}

void loop() {
  ThingSpeak.writeField(ChannelNo, 1, digitalRead(D1), API_Key);
  ThingSpeak.writeField(ChannelNo, 2, digitalRead(D2), API_Key);
  ThingSpeak.writeField(ChannelNo, 3, digitalRead(D3), API_Key);
  Serial.println("HELLO");
  delay(1000);
}
