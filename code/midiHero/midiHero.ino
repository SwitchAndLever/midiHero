/*
  MIDI Hero v1.0

  By Daniel Jansson // Switch & Lever // http://www.youtube.com/switchandlever/

  This sketch converts a Guitar Hero World Tour guitar into a functional USB MIDI device
  to play music, or use as a control interface, with a DAW or similar software.

  MIDI Hero relies on the use of an Arduino using an ATmel32u4 microcontroller, which is
  found in Arduino boards such as the Arduino Leonardo, Arduino Pro Micro, the Teensy as
  well as many others. This code will not work with regular ATmega328 boards, like the
  UNO, as they do not support simulating other hardware, like keyboards, mouse, or in
  this case a USB MIDI device.

  The MIDI Hero is accompanied by a build video available here:

  [YOUTUBE LINK TO BE PUT HERE]

  Depending on your build your pin assignments may differ. Make sure you watch the video
  about this project for more information on how to build your own.

  Due to different implementations in different DAW and MIDI software the MIDI data may
  or may not need to be shifted an octave up or down to have the correct notes for
  strumming. This is defined by the 'shift' variable below, change in intervals of 12
  (ie. -12, 0, 12, 24, etc) if need be.

  Libraries used:

  MIDIUSB: https://www.arduino.cc/reference/en/libraries/midiusb/
  SoftPWM: https://www.arduino.cc/reference/en/libraries/softpwm/

  Please refer to the documentation for the individual libraries on their respective
  operation and function.

  This code is licensed under a GNU General Public License and may be freely modified
  and redistributed under the same license terms.
  https://www.gnu.org/licenses/gpl-3.0.en.html

*/

#include "MIDIUSB.h"
#include "PitchToNote.h"
#define NUM_BUTTONS  5 // how many neck buttons

#include <SoftPWM.h>  // soft PWM library to give PWM function on non-PWM pins (LED fading)

// Pins assignments for neck buttons
const uint8_t orange = 6;
const uint8_t blue = 8;
const uint8_t yellow = 4;
const uint8_t red = 5;
const uint8_t green = 7;

const uint8_t buttons[NUM_BUTTONS] = {green, red, yellow, blue, orange};
const byte notePitches[NUM_BUTTONS] = {C2, E2, A2, C3, G3}; // pick notes from PitchToNote.h
uint8_t pressedButtons = 0x00;
uint8_t previousButtons = 0x00;
uint8_t intensity = 100;  // velocity

// Pin assignments
const uint8_t strumUp = 10;
const uint8_t strumDown = 9;

const uint8_t plus = 3;
const uint8_t bridge = 2;

const uint8_t emergency = 15;

const uint8_t led1 = 14;
const uint8_t led2 = 16;

const uint8_t joyV = 20; //A2 input
const uint8_t joyH = 19; //A1 input
const uint8_t whammy = 18; //A0 input

// Pin/button/potentiometer values
int pitchVal = 0;
int lastPitchVal = 0;

int modVal = 0;
int lastModVal = 0;

int whammyVal = 0;
int lastWhammyVal = 0;

int strumUpVal;
int strumDownVal;

uint8_t plusVal = 1;
uint8_t lastPlusVal = 1;
uint8_t bridgeVal = 1;
uint8_t lastBridgeVal = 1;

int emergencyVal;

const uint8_t diff = 2;

uint8_t octaveShiftVal = 0;
const uint8_t shift = 12;




void setup() {

  SoftPWMBegin(); // start SoftPWM function

  // Set up pins. Due to INPUT_PULLUP being defined for all buttons, which avoids
  // having to use external resistors, their logic is reversed. They will read 1 when
  // not pressed, and 0 when pressed.

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  pinMode(strumUp, INPUT_PULLUP);
  pinMode(strumDown, INPUT_PULLUP);
  pinMode(plus, INPUT_PULLUP);
  pinMode(bridge, INPUT_PULLUP);
  pinMode(emergency, INPUT_PULLUP);

  pinMode (joyV, INPUT);
  pinMode (joyH, INPUT);
  pinMode (whammy, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {

  readButtons();
  octaveShift();
  pitchWheel();
  modWheel();
  whammyBar();

  // if emergency switch is engaged play single strings without strum bar
  if (emergencyVal == 0) {
    LEDs(10);
    readNeck();
    playNotes();
  } else {
    LEDs(2);
  }

  // if emergency switch is not engaged, and strum bar is moved up
  // play a chord while strumming up
  if (emergencyVal == 1 && strumUpVal == 0 && strumDownVal == 1) {
    playChordUp();
  }

  // if emergency switch is not engaged, and strum bar is moved down
  // play a chord while strumming down
  if (emergencyVal == 1 && strumUpVal == 1 && strumDownVal == 0) {
    playChordDown();
  }

  // if emergency switch is not engaged, and strum bar is returned
  // to neutral position stop playing chord
  if (emergencyVal == 1 && strumUpVal == 1 && strumDownVal == 1) {
    endChord();
  }

}
