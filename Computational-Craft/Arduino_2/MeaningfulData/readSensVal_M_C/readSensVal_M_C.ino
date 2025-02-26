/*
   READING SENSOR VALUES W/MAP + CONSTRAIN
   Liza Stark
   Updated Feb 2025

   This sketch reads a textile sensor and fades an LED based on the sensor value. It incorporates the map() and constrain() functions.

   The sensor is attached to A5 through a 10k voltage divider. If you choose to use INPUT_PULLUP, remember to 
   update the logic so the LED brightens as you manipulate the sensor.
   The LED is on pin 9.

*/

int sensorPin = A5;
int sensorValue = 0;
int LEDpin = 9;
int newSensorValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(LEDpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor val = ");
  Serial.print(sensorValue);


  newSensorValue = map(sensorValue, 0, 1023, 0, 255);

  newSensorValue = constrain(newSensorValue, 0, 255);
  
  analogWrite(LEDpin, newSensorValue);

  Serial.print("\t");
  Serial.print("New sensor val = ");
  Serial.println(newSensorValue);

}
