#include <Arduino.h>
#include <Wifi.h>

const char *ssid = "ving";
const char *password = "22222222";

unsigned long previousMillis = 0;
unsigned long interval = 5000;

void WiFi_Init() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.print("\n");
  Serial.print("LocalIP: ");  
  Serial.println(WiFi.localIP()); // LocalIP of ESP32
}

void setup() {
  Serial.begin(9600);
  WiFi_Init();
}

void loop() {
  unsigned long currentMillis = millis();
  if (WiFi.status() != WL_CONNECTED && (currentMillis - previousMillis >= interval)) {
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    previousMillis = currentMillis;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("RSSI: ");
    Serial.println(WiFi.RSSI());
    delay(1000);
  }
}

/*
void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("Setup done!");
  delay(200);
}

void loop() {
  Serial.println("Scan start...");
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("No WiFi found");
  } else {
    Serial.println("Found: " + String(n) + " WiFi");
    for (int i = 0; i < n; i++) {
      Serial.println(String(i+1) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ")");
    }
  }
  delay(1000);
}
*/