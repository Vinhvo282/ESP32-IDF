#include <Arduino.h>

#define LED 5
#define BUTTON 18

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  digitalWrite(LED, LOW);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    delay(50); // Debounce delay
    digitalWrite(LED, HIGH);
  } else {
    delay(50); // Debounce delay
    digitalWrite(LED, LOW);
  }
}