/*
   A Simple Reflex Game
   by rowan07
   https://create.arduino.cc/projecthub/rowan07/a-simple-reflex-game-937472

*/

int ledPin = 13;
int sensorPin1 = 2;
int long ranDelay = 0;
int sensorValue = 0;
float realTime

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin1, INPUT);
}

void loop() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Push the button to start game");

  while (digitalRead(sensorPin1) == 0) {
  }
  
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Get Ready!");
  delay(1000);
  Serial.println("Get Set!");
  delay(1000);
  ranDelay = random(5000);
  delay(ranDelay);
  Serial.println("Go!");

  realTime = millis();
  digitalWrite(ledPin, HIGH);


  while (digitalRead(sensorPin1) == 0) {
  }
  
  digitalWrite(ledPin, LOW);
  Serial.println("Your time was");
  realTime = millis() - realTime;
  Serial.print(realTime / 1000, 2);
  Serial.println(" seconds");
  delay(2000);
