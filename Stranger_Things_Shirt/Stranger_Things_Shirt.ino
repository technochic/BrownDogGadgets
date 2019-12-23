// Code for Programmable Stranger Things Shirt
// By Natasha Dzurny for Brown Dog Gadgets

#include <Adafruit_NeoPixel.h>

#define PIN 14 // Connect Neopixels to pin 14
#define NUM_LEDS 15 // Change this to equal the total number of pixels

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800); //create a NeoPixel strip

// Variables to create colors without making the strip too bright
int red = 255;
int white = 150;
int green = 255;
int yellow = 255; // use in both red and green spots


// Name all the pixels by the letter they represent
int A = 11; // White
int C = 12; // Red
int E = 13; // Red
int H = 14; // Green
int I = 10; // Red
int L = 9; // Yellow
int M = 8; // Greem
int O = 7; // Red
int Q = 6; // Red
int R = 0; // Red
int S = 1; // Yellow
int T = 2; // Red
int W = 3; // REd
int letterY = 4; // white
int letterZ = 5; // yellow



void setup() {
  strip.begin();
  strip.show();
}

void loop() {

  ledFlashing(NUM_LEDS); // (Number Of Pixels That Flash) Flashes each Pixel Once at Random
  ledStayOn(50, 100); // (How Many LEDs, Brightness) Turns LEDs on and Chooses random LEDs to change to a random color
  allOn(100, 50); // (How Long they are on in milliseconds, Brightness) Turns all pixels on. Stick to values under 100 to avoid power issues
  strip.clear();
  delay(1000);
  merryChristmas(); // Spells "Merry Christmas"!
  delay(3000); // (How long you want the shirt to pause before spelling again in milliseconds)

}

void ledFlashing(int numberOfPixels) {

  for (int i = 0; i < numberOfPixels; i++) {

    int randomPixel = random(15);
    int colorBendR = random(50);
    int colorBendG = random(50);
    int colorBendB = random(50);

    strip.setPixelColor(randomPixel, colorBendR, colorBendG, colorBendB);
    strip.show();
    delay(20);
    strip.clear();
  }
}

void ledStayOn(int howManyLEDs, int bright) {
  for (int i = 0; i < howManyLEDs; i++) {

    int randomPixel = random(15);
    int colorBendR = random(bright);
    int colorBendG = random(bright);
    int colorBendB = random(bright);

    strip.setPixelColor(randomPixel, colorBendR, colorBendG, colorBendB);
    strip.show();
    delay(20);
  }
  strip.clear();
}

void allOn(int delayDuration, int bright) {
  for (int i = 0; i < 15; i++) {
    strip.setPixelColor(i, bright, bright, bright);
  }
  strip.show();
  delay(delayDuration);
  strip.clear();
}

void turnOnLetter(int theLetter, int redValue, int greenValue, int blueValue) {
  int letterDelay = 500;
  strip.setPixelColor(theLetter, redValue, greenValue, blueValue);
  strip.show();
  delay(letterDelay);
  strip.clear();

}

void merryChristmas() {
  turnOnLetter(M, 0, green, 0);
  turnOnLetter(E, red, 0, 0);
  turnOnLetter(R, red, 0, 0);
  doubleLetterDelay(R, 0, 0, 0);
  turnOnLetter(R, red, 0, 0);
  turnOnLetter (letterY, white*.8, white*.8, white*.8);
  turnOnLetter (letterY, 0, 0, 0);
  delay(100);
  turnOnLetter(C, red, 0, 0);
  turnOnLetter(H, 0, green, 0);
  turnOnLetter(R, red, 0, 0);
  turnOnLetter(I, red, 0, 0);
  turnOnLetter(S, yellow, yellow, 0);
  turnOnLetter(T, red, 0, 0);
  turnOnLetter(M, 0, green, 0);
  turnOnLetter(A, white, white, white);
  turnOnLetter(S, yellow, yellow, 0);
  turnOnLetter(S, 0, 0, 0);
}

void doubleLetterDelay(int theLetter, int redValue, int greenValue, int blueValue) {

  strip.setPixelColor(theLetter, redValue, greenValue, blueValue);
  strip.show();
  delay(100);
  strip.clear();

}
