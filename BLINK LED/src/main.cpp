#include <Arduino.h>

#define LED_PIN 5 // GPIO5

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn the LED on
  delay(200);                 
  digitalWrite(LED_PIN, LOW);  // Turn the LED off
  delay(200);                 
}
