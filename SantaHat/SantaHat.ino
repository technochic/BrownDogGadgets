// Code for Santa's Sorting Hat Project
// By Natasha Dzurny for Brown Dog Gadgets

#include <Servo.h> //Include the library that lets you command the servo
int buttonPin = 9; // This is pin D9 on the Crazy Circuits board
int LED = 13; // This is the LED on the board
boolean buttonGate = false;

Servo servo;
int angle = 0;
int startAngle = 95; // The position when the stick is straight up - change angle if necessary
int stageLeft = 30; //The left most position as if you were wearing it - change angle if necessary
int stageRight = 160; //The right most position as if you were wearing it - change angle if necessary

void setup() {

  servo.attach(3);   //Servo is connected to pin 3
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED, OUTPUT);   // Define pin #13 as output, for the LED

  servo.write(startAngle);
  delay(10);
  Serial.begin(9600);
}

void loop() {

  int buttonValue = digitalRead(buttonPin);
  if (!buttonGate) {
    if (buttonValue == LOW) {
      buttonGate = true;
      digitalWrite(LED, HIGH);
      angleDance(90, 100, 10); // Change if you'd like! The first number is the minimum angle,
      angleDance(60, 120, 7); //  the second is the maximum angle and the third is 
      angleDance(40, 150, 4); // how many times it wiggles
      chooseYourFate();
      delay(5000);
    }
  }

  else {
    buttonGate = false;
    digitalWrite(LED, LOW);
    servo.write(startAngle);
  }

}

int angleDance(int angleMin, int angleMax, int numberOfTimes) {
  int danceDelay = 200;

  for (int i = 0; i <= numberOfTimes; i++) {
    int randomAmount = random(angleMin, angleMax);
    Serial.println(randomAmount);
    servo.write(randomAmount);
    delay(danceDelay);
  }
}

void chooseYourFate() {
  long naughtyOrNice = random(2);

  if (naughtyOrNice == 0) {
    servo.write(stageLeft);

  } if (naughtyOrNice == 1) {
    servo.write(stageRight);
  }
    Serial.println(naughtyOrNice);
}
