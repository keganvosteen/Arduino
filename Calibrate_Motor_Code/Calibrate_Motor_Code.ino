//send motors to center position to attach bracket
//Prof is using dig pins 2 & 3

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
float arm2Home = 0;
int arm2Pin = 9;

//Servo claw;
//float clawHome = 90;
//int clawPin = 9;

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

  //Servo5.attach(Servo5Pin);
  //Servo5.write(Servo5Home);
}

void loop() {
  // put your main code here, to run repeatedly:

}
