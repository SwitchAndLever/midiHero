/*
  Plays a predefined chord as defined below. Hold one of the buttons on the neck and
  move the strum bar either up or down to play a chord.

  Has a short delay between each note of the chord sent to simulate strumming,
  rather than playing all notes at the exact same time. Set this 'chordDelay' below
  to a different amount if you want a slower or faster strum.

  Will not play a chord if none or more than one neck button is pressed.

  This code could probably be tidied up by using for-loops, and implemented more
  efficiently.

  Also left to do would be a way to dynamically change chords rather than having to
  reprogram the Arduino to change the five playable chords below.
*/

// Chords, copy required chords from ChordList.h
const uint8_t greenChord[] = {C2, E2, G2, C3, E3}; // C major
const uint8_t redChord[] = {A1, E2, A2, D3b, E3}; // A major
const uint8_t yellowChord[] = {G1, B1, D2, G2, B2, G3}; // G major
const uint8_t blueChord[] = {E1, B1, E2, A2b, B2, E3}; // E major
const uint8_t orangeChord[] = {D2, A2, D3, G3b}; // D major

const uint8_t chordDelay = 15; // delay between each note of the chord in ms
bool playedChord = 0; // flag which resets after chord is played


// Strum up  (reads chord array backwards to simulate strumming up)
void playChordUp() {

  if (digitalRead(buttons[0]) == LOW && playedChord == 0) {
    for (int i = sizeof(greenChord); i > 0; i--) {
      noteOn(0, (greenChord[i - 1]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[1]) == LOW && playedChord == 0) {
    for (int i = sizeof(redChord); i > 0; i--) {
      noteOn(0, (redChord[i - 1]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[2]) == LOW && playedChord == 0) {
    for (int i = sizeof(yellowChord); i > 0; i--) {
      noteOn(0, (yellowChord[i - 1]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[3]) == LOW && playedChord == 0) {
    for (int i = sizeof(blueChord); i > 0; i--) {
      noteOn(0, (blueChord[i - 1]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[4]) == LOW && playedChord == 0) {
    for (int i = sizeof(orangeChord); i > 0; i--) {
      noteOn(0, (orangeChord[i - 1]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
}


// Strum down
void playChordDown() {

  if (digitalRead(buttons[0]) == LOW && playedChord == 0) {
    for (int i = 0; i < sizeof(greenChord); i++) {
      noteOn(0, (greenChord[i]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[1]) == LOW && playedChord == 0) {
    for (int i = 0; i < sizeof(redChord); i++) {
      noteOn(0, (redChord[i]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[2]) == LOW && playedChord == 0) {
    for (int i = 0; i < sizeof(yellowChord); i++) {
      noteOn(0, (yellowChord[i]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[3]) == LOW && playedChord == 0) {
    for (int i = 0; i < sizeof(blueChord); i++) {
      noteOn(0, (blueChord[i]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }
  if (digitalRead(buttons[4]) == LOW && playedChord == 0) {
    for (int i = 0; i < sizeof(orangeChord); i++) {
      noteOn(0, (orangeChord[i]) + shift, 100);
      MidiUSB.flush();
      delay(chordDelay);
      playedChord = 1;
    }
  }

}


// Turns off chord when strum bar returns to center and resets 'playedChord'
// so the same or a new chord can be played.
void endChord() {

  if (playedChord == 1) {
    for (int i = 0; i < sizeof(greenChord); i++) {
      noteOff(0, (greenChord[i]) + shift, 0);
    }
    for (int i = 0; i < sizeof(redChord); i++) {
      noteOff(0, (redChord[i]) + shift, 0);
    }
    for (int i = 0; i < sizeof(yellowChord); i++) {
      noteOff(0, (yellowChord[i]) + shift, 0);
    }
    for (int i = 0; i < sizeof(blueChord); i++) {
      noteOff(0, (blueChord[i]) + shift, 0);
    }
    for (int i = 0; i < sizeof(orangeChord); i++) {
      noteOff(0, (orangeChord[i]) + shift, 0);
    }
    MidiUSB.flush();
    playedChord = 0;
  }
}
