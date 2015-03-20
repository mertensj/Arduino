
// SHARP IR Sensor
// 2Y0A21 F 24
#include <SharpIR.h>
int ledPIN = 13;
int irPIN = 0;   // analog pin 0
int speakerPin = 9;
int greenLed = 8;

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void playMelody() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

    // pause between notes
    delay(tempo / 2); 
  }
}


//	ir: the pin where your sensor is attached.
//	25: the number of readings the library will make before calculating an average distance.
//	93: the difference between two consecutive measurements to be taken as valid (in %)
//	model: is an int that determines your sensor:  1080 for GP2Y0A21Y, 20150 for GP2Y0A02Y
SharpIR sharp(irPIN, 25, 93, 1080);

void setup(void) {
  pinMode(ledPIN, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(greenLed, OUTPUT);

  Serial.begin(9600);

  //playMelody();
  playNote('c',tempo); delay(tempo/4); 
  playNote('d',tempo); delay(tempo/4);
  playNote('c',2*tempo); delay(tempo/4);
  playNote('C',tempo/2); delay(tempo/4);
  playNote('C',tempo/4); delay(tempo/4);
  playNote('C',tempo/6);

}

void loop() {
  int dis=sharp.distance();
  //Serial.println(dis);
  if (dis>150) {
    digitalWrite(greenLed, LOW);
    digitalWrite(ledPIN, HIGH);
    playNote('c',tempo); delay(tempo/4);
    playNote('C',tempo/2); delay(tempo/4);
    playNote('f',tempo/2); delay(tempo/4);
    playNote('f',tempo/2); delay(tempo/4);
  }
  else {
    digitalWrite(ledPIN, LOW);
    digitalWrite(greenLed, HIGH);
  }
  delay(1000);
}

