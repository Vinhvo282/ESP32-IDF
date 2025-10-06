#include <Arduino.h>

#define RES_VAR 34

void setup() {
  Serial.begin(115200);
  pinMode(RES_VAR, INPUT);
}

void loop() {
  int value = analogRead(RES_VAR);
  Serial.print("Value: ");
  Serial.println(value);
  delay(500);
}



