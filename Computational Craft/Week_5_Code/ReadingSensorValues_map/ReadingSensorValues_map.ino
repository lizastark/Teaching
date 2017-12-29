/*

 Reading Sensor Values with Mapping Function
 Comp Craft Spring 2013

 This sketch reads the data coming in from the
 sensor, maps it to a usable range, and writes
 the new value to an LED.

 map(value, fromLow, fromHigh, toLow, toHigh)
 https://www.arduino.cc/en/Reference/Map


 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 9;     // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int newSensorValue;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  //map the values to something usable
  //map(value, fromLow, fromHigh, toLow, toHigh)
  newSensorValue = map(sensorValue, 0, 1023, 0, 255);

  //write the new value to the LED
  analogWrite(ledPin, newSensorValue);

  //print the new value to the serial monitor
  Serial.print("newSensorValue = ");
  Serial.println(newSensorValue);

}
