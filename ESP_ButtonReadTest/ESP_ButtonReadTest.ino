int BlueButtonPin = 12;
int WhiteButtonPin = 14;
int RedButtonPin = 4;
int YellowButtonPin = 5;

int BlueVal = 0;
int WhiteVal = 0;
int RedVal = 0;
int YellowVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (BlueButtonPin, INPUT);
  pinMode (WhiteButtonPin, INPUT);
  pinMode (RedButtonPin, INPUT);
  pinMode (YellowButtonPin, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  BlueVal = digitalRead(BlueButtonPin);
  WhiteVal = digitalRead(WhiteButtonPin);
  RedVal = digitalRead(RedButtonPin);
  YellowVal = digitalRead(YellowButtonPin);

  Serial.print("Blue Val: ");
  Serial.print(BlueVal);
  Serial.print(" | White Val: ");
  Serial.print(WhiteVal);
  Serial.print(" | Red Val: ");
  Serial.print(RedVal);
  Serial.print(" | Yellow Val: ");
  Serial.println(YellowVal);

}
