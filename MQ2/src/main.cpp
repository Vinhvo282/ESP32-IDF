#include <Arduino.h>

#define MQ2_A0 35
#define MQ2_D0 34
#define LED 32

void setup() {
  pinMode(MQ2_D0, INPUT);
  pinMode(MQ2_A0, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(115200);
}

void loop() {
  int A0 = analogRead(MQ2_A0);
  int D0 = digitalRead(MQ2_D0);
  Serial.print("A0: ");
  Serial.print(A0);
  Serial.print(" | D0: ");
  Serial.println(D0);
  delay(1000);

  if (A0 > 1500) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}