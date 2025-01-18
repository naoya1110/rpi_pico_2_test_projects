#include <Arduino.h>

#define TONE_USE_INT
#define TONE_PITCH 440

// https://github.com/RodrigoDornelles/arduino-tone-pitch
#include <TonePitch.h>

const int ledPin = LED_BUILTIN;  // the number of the LED pin
int ledState = LOW;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(28, INPUT);
  Serial.begin(9600);
}

void loop()
{
  tone(6, 500);
  tone(7, 600);
  tone(8, 700);
  // tone(8, NOTE_C4);
  int sensorReading = analogRead(28);
  Serial.println(sensorReading);

  // if (sensorReading > 511) {
  //   ledState = HIGH;
  //   Serial.println("LED ON");
  // } else {
  //   ledState = LOW;
  //   Serial.println("LED OFF");
  // }

  if (ledState == LOW) {
    ledState = HIGH;
    Serial.println("LED ON");
  } else {
    ledState = LOW;
    Serial.println("LED OFF");
  }

  digitalWrite(ledPin, ledState);
  delay(200);
}