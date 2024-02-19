/*
 * Touch circuit
 * Spring 2024
 * Computational Craft || MFADT Parsons
 * 
 * This is a bit noisy, but it is a cool option depending on your constraints.
 * 
 * Adapted from Dave Mellis' ATtiny touch sketch
 * http://highlowtech.org/?p=1653
 * 
 */



int touchpin = PB4; // this is pin 12
int togglepin = 3; // the led that's toggled when you touch the input pin

int calibration = 0;
int previous;

int randomval = 0;
int fadeval = 0, fadestep = 1;
int togglestate = LOW;

void setup()
{
  pinMode(togglepin, OUTPUT);

  delay(100);
  for (int i = 0; i < 8; i++) {
    calibration += chargeTime(touchpin); //This is pin 
    delay(20);
  }
  calibration = (calibration + 4) / 8;
}

void loop()
{
  //TOUCH
  // read sensor value from touch sensor
  int n = chargeTime(touchpin);

  if (previous <= calibration && n > calibration) {
    if (togglestate == LOW) togglestate = HIGH;
    else togglestate = LOW;

    digitalWrite(togglepin, togglestate);
  }

  previous = n;

  delayMicroseconds(500);

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
