//send motors to center position to attach bracket
//Prof is using dig pins 2 & 3
//change names to Servo1, Servo2, Servo3 etc

#include<Servo.h>

Servo base;
float baseHome = 90;
int basePin = 3;


Servo firstLink;
float firstLinkHome = 90;
int firstLinkPin = 4;

Servo arm1;
float arm1Home = 90;
int arm1Pin = 5;

Servo arm2;
float arm2Home = 100;
int arm2Pin = 9;

Servo claw;
float clawHome = 90;
int clawPin = 10;

void setup() {
  // put your setup code here, to run once:
  base.attach(basePin);
  base.write(baseHome);
  
  firstLink.attach(firstLinkPin);
  firstLink.write(firstLinkHome);

  arm1.attach(arm1Pin);
  arm1.write(arm1Home);

  arm2.attach(arm2Pin);
  arm2.write(arm2Home);

  claw.attach(clawPin);
  claw.write(clawHome);

}

void loop() {
  // put your main code here, to run repeatedly:

}
