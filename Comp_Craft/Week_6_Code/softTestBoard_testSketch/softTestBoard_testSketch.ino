/*
  Week 6 Soft Testing Board - Switch sketch

  Use this to test your vinyl cut or embroidered test board.
  To simplify, we do not have a pull down resistor
  on the switch pins, so we need to account for this in software.

  You can also use this board for a sensor but will need to adapt
  the mapping on the sketches from Week 4: https://github.com/lizastark/Teaching/tree/master/Comp_Craft/Week_4_Code 

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial
*/

int topLED = 9;
int bottomLED = 6;
int switchPin = 2;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(topLED, OUTPUT);
  pinMode(bottomLED, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int switchVal = digitalRead(switchPin);
  //print out the value of the pushbutton
  Serial.println(switchVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (switchVal == HIGH) {
    digitalWrite(topLED, LOW);
    digitalWrite(bottomLED, LOW);
  } else {
    digitalWrite(topLED, HIGH);
    digitalWrite(bottomLED, HIGH);
  }
}
