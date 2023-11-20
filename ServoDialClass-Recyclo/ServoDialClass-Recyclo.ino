#include <Servo.h> //include the servo library
Servo base;
int basePin = 3;

Servo firstLink;
int firstLinkPin = 4;

Servo arm1;
int arm1Pin = 5;

Servo arm2;
int arm2Pin = 9;

Servo claw;
int clawPin = 10;

int prevVal1 = 0;
int prevVal2 = 0;
int prevVal3 = 0;
int prevVal4 = 0;
int prevVal5 = 0;

//0 corresponds to 0
//180 corresponds to 270 degrees (max position of the servo)

int basePotPin = A0; //only input, no definition
int basePotValue = 0; //store potentiometer value

int firstLinkPotPin = A1;
int firstLinkPotValue = 0; 

int arm1PotPin = A2;
int arm1PotValue = 0; 

int arm2PotPin = A3;
int arm2PotValue = 0;

int clawPotPin = A4;
int clawPotValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  base.attach(basePin);
  //base.write(baseHome);
  
  firstLink.attach(firstLinkPin);
  //firstLink.write(firstLinkHome);

  arm1.attach(arm1Pin);
  //arm1.write(arm1Home);

  arm2.attach(arm2Pin);
  //arm2.write(arm2Home);

  claw.attach(clawPin);
  //claw.write(clawHome);
}

void loop() {
  // put your main code here, to run repeatedly:
  basePotValue = analogRead(basePotPin);
  basePotValue = map(basePotValue,0,1023,0,180);
  base.write(basePotValue);


  firstLinkPotValue = analogRead(firstLinkPotPin);
  firstLinkPotValue = map(firstLinkPotValue,0,1023,0,180);
  firstLink.write(firstLinkPotValue);
  
  arm1PotValue = analogRead(arm1PotPin);
  arm1PotValue = map(arm1PotValue,0,1023,0,180);
  arm1.write(arm1PotValue);
  
  arm2PotValue = analogRead(arm2PotPin);
  arm2PotValue = map(arm2PotValue,0,1023,0,180);
  arm2.write(arm2PotValue);
  
  clawPotValue = analogRead(clawPotPin);
  clawPotValue = map(clawPotValue,0,1023,0,180);
  claw.write(clawPotValue);

  if((prevVal1 != basePotValue) || (prevVal2 != firstLinkPotValue) || (prevVal3 != arm1PotValue) || (prevVal4 != arm2PotValue) || (prevVal5 != clawPotValue))
  {
    Serial.print("Base: ");
    Serial.println(basePotValue);
    Serial.print("firstLink: ");
    Serial.println(firstLinkPotValue);
    Serial.print("arm1: ");
    Serial.println(arm1PotValue);
    Serial.print("arm2: ");
    Serial.println(arm2PotValue);
    Serial.print("claw: ");
    Serial.println(clawPotValue);
    prevVal1 = basePotValue;
    prevVal2 = firstLinkPotValue;
    prevVal3 = arm1PotValue;
    prevVal4 = arm2PotValue;
    prevVal5 = clawPotValue;    
  }
  
}
