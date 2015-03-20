#include <Arduino.h>

// Blink
int ledPin = 13;
int motorPin = 3;
int photocellPin = 0; // the cell and 10K pulldown are connected to a0
int photocellReading; // the analog reading from the sensor divider
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;    //  

void setup(void) {
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while ( ! Serial);
  Serial.println("setup");
}

void led(int time) {
  digitalWrite(ledPin, HIGH); delay(time);
  digitalWrite(ledPin, LOW);
}
void motor(int speed) {
  analogWrite(motorPin, speed); delay(1000);
}

void loop() {
  led(200);
  photocellReading = analogRead(photocellPin);
  Serial.print("Analog reading = ");
  Serial.println(photocellReading); // the raw analog reading
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  //photocellReading = 1023 - photocellReading;
  photocellReading = 700 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 700, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
  delay(200);
}

