/*
  Soft Switch with Circuit Playground Express
  Comp Craft Spring 2025
 
  This sketch turns a neopixel on and off when a switch is closed on pin 11 (i.e. A2). It 
  uses the CPX library to turn on a single LED and multiple LEDs using a for loop.

  The circuit:
  - soft switch attached to digital pin 9 from +3V
  - 10K resistor attached to pin 9 from ground

  Based on button example in File > Examples > Digital > Button

*/

#include <Adafruit_CircuitPlayground.h>
const int buttonPin = 9;  // the number of the pushbutton pin. const means that the value won't change
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  //configure CPX and neopixels
  CircuitPlayground.begin(); //Required
  CircuitPlayground.clearPixels();
  CircuitPlayground.strip.setBrightness(200); //255 is the max

  //start serial monitor
  Serial.begin(9600);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    CircuitPlayground.strip.setPixelColor(6, 0, 0, 255);
    Serial.println("Pressed!");
  } else {
    // turn LED off:
    CircuitPlayground.strip.setPixelColor(6, 0, 0, 0);
    Serial.println("Not pressed");
  }
  //always tell CPX to display the neopixels
  CircuitPlayground.strip.show();
}

// as a next step, see if you can have it control multiple neopixels!
