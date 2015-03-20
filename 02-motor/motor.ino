
// Blink
int ledPin = 13;
int RmotorPin = 3;
int LmotorPin = 5;
int MinSpeed = 200;

void setup(void) {
  pinMode(ledPin, OUTPUT);
  pinMode(RmotorPin, OUTPUT);
  pinMode(LmotorPin, OUTPUT);
  //Serial.begin(9600);
  //while ( ! Serial);
  //Serial.println("Speed 0 to 255");
}

void led(int time) {
  digitalWrite(ledPin, HIGH); delay(time);
  digitalWrite(ledPin, LOW);
}
void Lmotor(int speed) {
  analogWrite(LmotorPin, speed); delay(1000);
}
void Rmotor(int speed) {
  analogWrite(RmotorPin, speed); delay(1000);
}

void loop() {
  led(100);
  Rmotor(250);
  Rmotor(0);
  Lmotor(200);
  Lmotor(50);
  Lmotor(200);
  Lmotor(50);
  Lmotor(200);
  Lmotor(50);
  Lmotor(200);
  Lmotor(50);
  Lmotor(200);
  Lmotor(0);

  //if (Serial.available())
  // {
  //  int speed = Serial.parseInt();
  //  motor(speed);
  //}
}

