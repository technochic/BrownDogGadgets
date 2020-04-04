// Code for DIY L"egg"o Amazing Egg Decorator with Lego
// By Natasha Dzurny for Brown Dog Gadgets

// Circuit: Connect Potentiometers to A0, A3 and A5, Connect the grey servos to D3 and D5, and the orange servo to D6



#include <Servo.h> //Include the library that lets you command the servo

Servo servoAngle;
Servo servoTilt;
Servo servoDrive;

const int servoAnglePin = 3;
const int servoTiltPin = 5;
const int servoDrivePin = 6;

int readLeft = A0;
int readMid = A3;
int readRight = A5;

int leftValue = 0;
int midValue = 0;
int rightValue = 0;

int leftPosition;
int midPosition;
int rightPosition;



void setup() {
  servoAngle.attach(servoAnglePin);
  servoTilt.attach(servoTiltPin);
  servoDrive.attach(servoDrivePin);
  Serial.begin(9600);
}

void loop() {

  leftValue = analogRead(readLeft);
  midValue = analogRead(readMid);
  rightValue = analogRead(readRight);

  leftPosition = map(leftValue, 0, 1023, 0, 100);
  midPosition = map(midValue, 0, 1023, 0, 100);// 179
  rightPosition = map(rightValue, 0, 1023, 0, 179); 

  Serial.print("leftPosition: ");
  Serial.print(leftPosition);
  Serial.print("  midPosition: ");
  Serial.println(midPosition);

  servoAngle.write(leftPosition);
  servoTilt.write(midPosition);

  if (rightPosition >= 80) {
    servoDrive.write(rightPosition);
  } else if (rightPosition <= 179) {
    servoDrive.write(rightPosition);
  } else if (rightPosition >= 81 && rightPosition <= 99) {
    servoDrive.write(90);
  }

  delay(15);

}
