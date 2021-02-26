/*
  Reads the whammy bar and converts the output to pitch bend

  The bar is read linearly for the first part of its travel and then ticks
  over into fully engaged for the rest. This response could likely be
  improved, either by replacing the potentiometer with a less noisy one,
  or by coding its response differently.

  Read the comment at the bottom of 'readJoystickV' for how the 14 bit
  pitch bend message is constructed.
*/

void whammyBar() {  // checks last value before sending a new MIDI message

  byte channel = 0xE0;
  int diff = 2;

  whammyVal = analogRead(whammy);
  int whammyValDiff = whammyVal - lastWhammyVal;

  if (abs(whammyValDiff) > diff)
  {

    // construct 14 bit pitch bend value
    int modulation = map(whammyVal, 1023, 935, 0, 8000);
    modulation = constrain(modulation, 0, 8000);
    unsigned int change = 0x2000 + modulation;  //  0x2000 == no Change
    byte low = change & 0x7F;
    byte high = change >> 7;

    midiEventPacket_t whammy = {0x0E, 0xE0 | channel, low, high};
    MidiUSB.sendMIDI(whammy);
    MidiUSB.flush();
    lastWhammyVal = whammyVal;
  }

  delay(2);

}
