/*
 * ATtiny Soft and Touch Sensor Circuit
 * February 18, 2017
 * Liza Stark
 * 
 * Textile Academy Bootcamp
 * More info at softcircuiteer.net/bcn-attiny-workshop
 * 
 * Adapted from Dave Mellis' ATtiny touch sketch
 * http://highlowtech.org/?p=1653
 * 
 */



//                        attiny85/45
//                   reset -+---+- power
//       (touch LED) pin 3 -+*  +- pin A1 (reads sensor)
//       (reads touch) pb4 -+   +- pb1 (fading while touching)
//                  ground -+---+- pb0 


int fadepin = 1; // the LED that fades when reading sensor values
int togglepin = 3; // the led that's toggled when you touch the input pin

int sensorpin = A1; // attach your sensor here
int sensorValue = 0;  // variable to store the value coming from the sensor
int newSensorValue;

int calibration = 0;
int previous;

int randomval = 0;
int fadeval = 0, fadestep = 1;
int togglestate = LOW;

void setup()
{
  pinMode(fadepin, OUTPUT);
  pinMode(togglepin, OUTPUT);
  pinMode(sensorpin, INPUT);

  delay(100);
  for (int i = 0; i < 8; i++) {
    calibration += chargeTime(PB4);
    delay(20);
  }
  calibration = (calibration + 4) / 8;
}

void loop()
{
  //TOUCH
  // read sensor value from touch sensor
  int n = chargeTime(PB4);

  if (previous <= calibration && n > calibration) {
    if (togglestate == LOW) togglestate = HIGH;
    else togglestate = LOW;

    digitalWrite(togglepin, togglestate);
  }

  previous = n;

  delayMicroseconds(500);

  // SENSOR
  // read the value from the sensor:
  sensorValue = analogRead(sensorpin);

  //map the values to something usable
  //map(value, fromLow, fromHigh, toLow, toHigh)
  newSensorValue = map(sensorValue, 0, 1023, 0, 255);

  //write the new value to the LED
  analogWrite(fadepin, newSensorValue);

}

byte chargeTime(byte pin)
{
  byte mask = (1 << pin);
  byte i;

  DDRB &= ~mask; // input
  PORTB |= mask; // pull-up on

  for (i = 0; i < 16; i++) {
    if (PINB & mask) break;
  }

  PORTB &= ~mask; // pull-up off
  DDRB |= mask; // discharge

  return i;
}

