#include <Keyboard.h>

//switch variables
int buttonPin = 3;    //A4 on CPX
int buttonState = 0;  // variable for reading the pushbutton status
int LEDpinBtn = 10;   //A3 on CPX

//sensor variables
int sensorPin = A5;
int sensorValue = 0;
int newSensorValue;
int LEDpin = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(LEDpin, INPUT);
  pinMode(LEDpinBtn, INPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  //Switch
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LEDpinBtn, HIGH);
    Keyboard.write('G');
    Serial.print("Button on");
    Serial.print("\t");
  } else {
    // turn LED off:
    digitalWrite(LEDpinBtn, LOW);
    Serial.print("Button off");
    Serial.print("\t");
  }
delay(10);


  // //Sensor
  // //read the sensor value
  // sensorValue = analogRead(sensorPin);
  // Serial.print("Sensor val = ");
  // Serial.print(sensorValue);

  // //map the value
  // newSensorValue = map(sensorValue, 0, 1023, 0, 255);

  // //type the letter Z
  // if (newSensorValue > 170 && newSensorValue < 175) {
  //   Keyboard.write('Z');
  // }
  // //turn on the LED
  // analogWrite(LEDpin, newSensorValue);

  // Serial.print("\t");
  // Serial.print("New sensor val = ");
  // Serial.println(newSensorValue);
}
