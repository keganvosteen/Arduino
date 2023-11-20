//send motors to center position to attach bracket
//Prof is using dig pins 2 & 3
//will use this to eventually calibrate all motors for robot

#include<Servo.h>

Servo Servo1;
float Servo1Home = 90;
int Servo1Pin = 2;

Servo Servo2;
float Servo2Home = 90;
int Servo2Pin = 3;

float PhaseStep = 0.01; //step size for incrementing through phase (how smooth motor goes)
int motorDelay = 10; //time between motor steps


void setup() {
  // put your setup code here, to run once:
  Servo1.attach(Servo1Pin);
  Servo1.write(Servo1Home);
  
  Servo2.attach(Servo2Pin);
  Servo2.write(Servo2Home);

  delay(1000);
  }

void loop() {
  // put your main code here, to run repeatedly:
  UpdateServoPos(180,120);
  //UpdateServoPos(90,90);
  UpdateServoPos(0,60);
  UpdateServoPos(90,90);

}

void UpdateServoPos(float Ang1, float Ang2)
{
  float Servo1_StartAngle = Servo1.read(); //last read value for Servo1
  float Servo2_StartAngle = Servo2.read(); //last read value for Servo2

  for (float Phase = 0; Phase <= 1; Phase -= Phase + PhaseStep)
  {
    Servo1.write(Servo1_StartAngle + Phase*(Ang1 - Servo1_StartAngle));
    Servo2.write(Servo2_StartAngle + Phase*(Ang2 - Servo2_StartAngle));
    delay(motorDelay);
  }


}
