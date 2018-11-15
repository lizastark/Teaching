/*
 * Thermochromic Ink Test - digitalWrite()
 * 
 * Connect heating element through a MOSFET transistor
 * (here I'm using an FQP30N06L). 
 * Gate: connect to pin 9 or any other PWM pin
 * Drain: connect to a one end of the heating element
 * Source: connect to ground of Arduino and second power source
 * 
 * See this post for lots more information:
 * http://thesoftcircuiteer.net/heating-circuits-for-thermochromic-inks/
 * 
 */

void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  Serial.begin(9600);

void loop() {
  // put your main code here, to run repeatedly:

  //Turn the secondary power source on:
  digitalWrite(2, HIGH);
  Serial.println("ON");
  //Change the delay to keep the heat on longer
  delay(700);
  
  //Turn it off to give your circuit a break
  digitalWrite(2, LOW);
  Serial.println("OFF");
  //Increase the delay to bring the color back
  delay(4000);

}
