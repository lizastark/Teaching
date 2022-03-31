// TEENSY AUDIO PLAYER - SKIP TRACKS
// Whe the buttons are pressed, stop playing
// the current file and skip to the next or previous.
// 
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
#include <Bounce.h>

AudioPlaySdWav           playSdWav1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

Bounce button0 = Bounce(20, 15);
Bounce button2 = Bounce(21, 15);  // 15 = 15 ms debounce time

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
  pinMode(21, INPUT_PULLUP);
  delay(1000);
}

int filenumber = 0;  // while file to play

const char * filelist[4] = {
  "SDTEST1.WAV", "SDTEST2.WAV", "SDTEST3.WAV", "SDTEST4.WAV"
};

void loop() {
  
  if (playSdWav1.isPlaying() == false) {
    const char *filename = filelist[filenumber];
    filenumber = filenumber + 1;
    if (filenumber >= 4) filenumber = 0;
    Serial.print("Start playing ");
    Serial.println(filename);
    playSdWav1.play(filename);
    delay(10); // wait for library to parse WAV info
  }
  
  // read pushbuttons
  button0.update();
  if (button0.fallingEdge()) {
    playSdWav1.stop();
  }
  button2.update();
  if (button2.fallingEdge()) {
    playSdWav1.stop();
    filenumber = filenumber - 2;
    if (filenumber < 0) filenumber = filenumber + 4;
  }
  
}
