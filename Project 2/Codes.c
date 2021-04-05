#include <Servo.h>

const int tiltPin = 4;
const int ledPin = 3;
const int togglePin = 5;
//green servo 9
Servo servG;
//purple servo 10
Servo servP;

void setup() {
 Serial.begin(9600);
 pinMode(ledPin, OUTPUT);
 pinMode(tiltPin, INPUT);
 pinMode(togglePin, INPUT);
 servP.attach(10);
 servG.attach(9);
}
void loop() {
  int state = 0;
  int tilt;
  tilt = digitalRead(tiltPin);
  int toggle;
  toggle = digitalRead(togglePin);
  while(state == 0){
    Serial.print("State 0");
    digitalWrite(ledPin, LOW);
    servP.write(0);
    servG.write(50);
    toggle = digitalRead(togglePin);
    if(toggle == LOW){
      Serial.print("low");
    }
    if(toggle == HIGH){
      Serial.print("high");
    }
    if(toggle == HIGH){
      state = 1;
    }
  }
  while(state == 1){
    Serial.print("State 1");
    digitalWrite(ledPin, HIGH);
    toggle = digitalRead(togglePin);
    if(toggle == HIGH){
      Serial.print("high");
    }
    if(toggle == LOW){
      Serial.print("low");
      state = 0;
      return;
    }
    tilt = digitalRead(tiltPin);
    if(tilt == LOW){
       state = 2;
    }
  }
  while(state == 2){
    Serial.print("State 2");
    digitalWrite(ledPin, LOW);
    servP.write(50);
    servG.write(0);
    toggle = digitalRead(togglePin);
      if(toggle == LOW){
        state = 0; 
      }
  }
}
