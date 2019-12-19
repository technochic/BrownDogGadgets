#include <Servo.h>
int buttonPin = 9;
int LED = 13;
boolean buttonGate = false;

Servo servo;
int angle = 0;
int startAngle = 95; // The position when the stick is straight up
int stageLeft = 30; //The left most position as if you were wearing it
int stageRight = 160; //The right most position as if you were wearing it

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
      angleDance(90, 100, 10);
      angleDance(60, 120, 7);
      angleDance(40, 150, 4);
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
