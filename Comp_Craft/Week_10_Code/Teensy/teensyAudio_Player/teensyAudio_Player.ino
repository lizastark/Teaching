// TEENSY AUDIO PLAYER - START STOP 
// When button is pressed, start playing and when
// pressed again, stop playing.

// ***Credits***
// Advanced Microcontroller-based Audio Workshop - Part 1-5
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
//


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce2.h>

AudioPlaySdWav           playSdWav1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

Bounce button0 = Bounce(20, 15);  // 15 = 15 ms debounce time

int playFile = LOW; // Set initial value to low

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

void setup() {
  Serial.begin(9600);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  pinMode(20, INPUT_PULLUP);
  delay(1000);
}


void loop() {

  // Read the button and update its status.
  button0.update();

  // Check for a high to low transition
  if ( button0.fallingEdge() ) {
    // Toggle state
    playFile = !playFile; // SET playFile TO THE OPPOSITE OF playFile

    // If state is low, stop playing but if high, start playing
    if (playFile == LOW) {
      playSdWav1.stop();
    } else if (playFile == HIGH) {
      playSdWav1.play("SDTEST4.WAV"); // Add correct file name
    }

  }


}
