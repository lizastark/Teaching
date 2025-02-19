/*

 Trigger Fading with Switch
 Neopixels with Circuit Playground Express
 Comp Craft Spring 2025
 
 When the switch is pressed, the neopixel turns red and begins 
 fading. When the switch is released, the neopixel stays magenta. 
 The fading is done with millis() to avoid blocking any incoming 
 sensor or switch readings by using delay(). This also includes a
 commented out example of fading a color other than red, green, or
 blue using map(). 
 
 */
 
 #include <Adafruit_CircuitPlayground.h>

int buttonPin = 9;
int brightness = 0;
int fadeAmount = 5;
unsigned long previousMillis = 0;
const long interval = 30;  // Adjust fade speed

bool fading = false;  // Track if fading is active

void setup() {
  CircuitPlayground.begin();
  pinMode(buttonPin, INPUT_PULLUP); // CPX buttons use pull-up resistors
}

void loop() {
  // Read the button state
  if (digitalRead(buttonPin) == LOW) { 
    fading = true;  // Start fading when button is pressed
  } else {
    fading = false;  // Hold steady color when button is not pressed
  }

  if (fading) {
    // Non-blocking fade logic
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      brightness += fadeAmount;
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount; // Reverse fade direction
      }

      // Fade in red color
      CircuitPlayground.setPixelColor(0, brightness, 0, 0);

      // // Fade an RGB color - requires more setup
      // // Create a pink fade using a proportional scaling of (255, 100, 150)
      // int r = map(brightness, 0, 255, 0, 255);  // Max Red
      // int g = map(brightness, 0, 255, 0, 20);  // Lower Green
      // int b = map(brightness, 0, 255, 0, 147);  // Medium Blue
      // CircuitPlayground.setPixelColor(0, r, g, b);
    }
  } else {
    // Keep a steady pink when button is NOT pressed
    CircuitPlayground.setPixelColor(0, 255, 20, 147);
  }
}
