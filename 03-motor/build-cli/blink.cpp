#include <Arduino.h>

// Blink
int ledPin = 13;
int motorPin = 3;

void setup(void) {
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(100);
  analogWrite(motorPin, 50);
  delay(500);
  analogWrite(motorPin, 0);
}

