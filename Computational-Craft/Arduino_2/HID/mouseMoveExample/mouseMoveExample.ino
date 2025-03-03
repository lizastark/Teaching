/*
   MOUSE CONTROL: Arduino as HID
   Liza Stark
   Updated March 2025

   This sketch uses two buttons to control the mouse movement. Remember that this allows your Arduino 
   to take over your whole machine, so keep this in mind as you edit the sketch.

   Documentation: https://docs.arduino.cc/libraries/mouse/ 
*/

#include <Mouse.h>

const int rightBtn = 6;  // A1 on CPX
const int leftBtn = 9;  // A2 on CPX

int rightBtnVal = 0;
int leftBtnVal = 0;

void setup() {
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(leftBtn, INPUT_PULLUP);
  Mouse.begin();  // Start mouse emulation
}

void loop() {
  rightBtnVal = digitalRead(rightBtn);
  leftBtnVal = digitalRead(leftBtn);

  if (rightBtnVal == LOW) {  // Right button is pressed
    Mouse.move(5, 0, 0);  // Move mouse right
    delay(50);
    Mouse.move(0, 5, 0);  // Move mouse down
    delay(50);
    
  }

  if (leftBtnVal == LOW) {  // Left button is pressed
    Mouse.move(-5, 0, 0);  // Move mouse left
    delay(50);
    Mouse.move(0, -5, 0);  // Move mouse up
    delay(50);
  }
  
}