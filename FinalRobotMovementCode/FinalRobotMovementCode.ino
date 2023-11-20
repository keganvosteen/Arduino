
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

float PhaseStep = 0.01; //step size for incrementing through phase (how smooth motor goes)
int motorDelay = 10; //time between motor steps

void UpdateBasePos(float angleToMoveTo)
{
  float Servo1_StartAngle = base.read(); //last read value for Servo1
  
  for (float Phase = 0; Phase <= 1; Phase = Phase + PhaseStep)
  {
    base.write(Servo1_StartAngle + Phase*(angleToMoveTo - Servo1_StartAngle));
    delay(motorDelay);
  }
}

void UpdateArm1Pos(float angleToMoveTo)
{
  float Servo1_StartAngle = arm1.read(); //last read value for Servo1
  
  for (float Phase = 0; Phase <= 1; Phase = Phase + PhaseStep)
  {
    arm1.write(Servo1_StartAngle + Phase*(angleToMoveTo - Servo1_StartAngle));
    delay(motorDelay);
  }
}

void UpdateArm2Pos(float angleToMoveTo)
{
  float Servo1_StartAngle = arm2.read(); //last read value for Servo1
  
  for (float Phase = 0; Phase <= 1; Phase = Phase + PhaseStep)
  {
    arm2.write(Servo1_StartAngle + Phase*(angleToMoveTo - Servo1_StartAngle));
    delay(motorDelay);
  }
}

void UpdateFirstLinkPos(float angleToMoveTo)
{
  float Servo1_StartAngle = firstLink.read(); //last read value for Servo1
  
  for (float Phase = 0; Phase <= 1; Phase = Phase + PhaseStep)
  {
    firstLink.write(Servo1_StartAngle + Phase*(angleToMoveTo - Servo1_StartAngle));
    delay(motorDelay);
  }
}

void UpdateClawPos(float angleToMoveTo)
{
  float Servo1_StartAngle = claw.read(); //last read value for Servo1
  
  for (float Phase = 0; Phase <= 1; Phase = Phase + PhaseStep)
  {
    claw.write(Servo1_StartAngle + Phase*(angleToMoveTo - Servo1_StartAngle));
    delay(motorDelay);
  }
}

void robotGoHome(bool shouldIOpenClaw) {
  UpdateFirstLinkPos(90);
  UpdateArm1Pos(90);
  UpdateArm2Pos(90);
  if (shouldIOpenClaw == true)
  {
    UpdateClawPos(85);
  }
  UpdateBasePos(90);
}

void robotReset() {
  UpdateFirstLinkPos(90);
  UpdateArm1Pos(90);
  UpdateArm2Pos(90);
  UpdateClawPos(122);
  UpdateBasePos(90);
}

void robotGoFetch()
{
  UpdateBasePos(113);
  delay(500);
  UpdateArm2Pos(28);
  delay(500);
  UpdateArm1Pos(118);
  delay(500);
  UpdateFirstLinkPos(55);
  delay(500);
  UpdateClawPos(122);
}

void robotGoFrontLeft()
{
  UpdateBasePos(85);
  delay(500);
  UpdateArm1Pos(143);
  delay(500);
  UpdateArm2Pos(35);
  delay(500);
  UpdateFirstLinkPos(90);
  delay(500);
  UpdateClawPos(90);
}

void robotGoFrontRight()
{
  UpdateBasePos(69);
  delay(500);
  UpdateArm1Pos(149);
  delay(500);
  UpdateArm2Pos(50);
  delay(500);
  UpdateFirstLinkPos(90);
  delay(500);
  UpdateClawPos(90);
}

void robotGoBackLeft()
{
  UpdateBasePos(84);
  delay(500);
  UpdateArm1Pos(138);
  delay(500);
  UpdateArm2Pos(69);
  delay(500);
  UpdateFirstLinkPos(76);
  delay(500);
  UpdateClawPos(90);
}

void robotGoBackRight()
{
  UpdateBasePos(73);
  delay(500);
  UpdateArm1Pos(128);
  delay(500);
  UpdateArm2Pos(68);
  delay(500);
  UpdateFirstLinkPos(71);
  delay(500);
  UpdateClawPos(90);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  base.attach(basePin);
  firstLink.attach(firstLinkPin);
  arm1.attach(arm1Pin);
  arm2.attach(arm2Pin);
  claw.attach(clawPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Starting...");
  delay(500);
  
  //Back Left
  Serial.println("Going home...");
  robotGoHome(true);
  delay(500);
  Serial.println("Fetching...");
  robotGoFetch();
  Serial.println("Fetched");
  delay(500);
  robotGoHome(false);
  delay(500);
  Serial.println("Headed to Back Left");
  robotGoBackLeft();
  delay(500);

  //Back Right
  Serial.println("Going home...");
  robotGoHome(true);
  delay(500);
  Serial.println("Fetching...");
  robotGoFetch();
  Serial.println("Fetched");
  delay(500);
  robotGoHome(false);
  delay(500);
  Serial.println("Headed to Back Right");
  robotGoBackRight();
  delay(500);
  
  //Front Left
  Serial.println("Going home...");
  robotGoHome(true);
  delay(500);
  Serial.println("Fetching...");
  // robotGoHome(&firstLink, &claw, &arm1, &arm2, &base);
  // delay(5000);
  robotGoFetch();
  Serial.println("Fetched");
  delay(500);
  robotGoHome(false);
  delay(500);
  Serial.println("Headed to Front Left");
  robotGoFrontLeft();
  delay(500);

  //Front Right
  Serial.println("Going home...");
  robotGoHome(true);
  delay(500);
  Serial.println("Fetching...");
  robotGoFetch();
  Serial.println("Fetched");
  delay(500);
  robotGoHome(false);
  delay(500);
  Serial.println("Headed to Front Right");
  robotGoFrontRight();
  delay(500);
  

}
