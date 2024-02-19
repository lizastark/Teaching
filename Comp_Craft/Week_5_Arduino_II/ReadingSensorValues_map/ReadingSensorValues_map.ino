int sensorPin = A0;
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

  newSensorValue = map(sensorValue, 30, 800, 0, 255);
  
  analogWrite(LEDpin, newSensorValue);

  Serial.print("\t");
  Serial.print("New sensor val = ");
  Serial.println(newSensorValue);

}
