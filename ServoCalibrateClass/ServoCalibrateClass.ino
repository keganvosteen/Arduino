#include <Servo.h> //include the servo library
Servo myservo; //create servo object to control your servo

int ServoPin = 10;
int pos = 90; // 90 corresponds to 135 degree (the middle position of the servo

//0 corresponds to 0
//180 corresponds to 270 degrees (max position of the servo)

int PotPin = 5; //only input, no definition
int PotValue = 0; //store potentiometer value

void setup() {
  // put your setup code here, to run once:
  myservo.attach(ServoPin); //attaches the servo to pin
  myservo.write(pos);
}

void loop() {
  // put your main code here, to run repeatedly:

}
