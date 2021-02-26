/*
  Reads vertical joystick, assigns and outputs its value to pitch wheel

  Checks last value and will only send a new value if the new value differs
  by more than 'diff' to avoid the slight noise which potentiometers can
  have at rest, so it doesn't constantly keep sending messages which slows
  down the sketch. If your potentiometer is very noisy this value may need
  increasing, though you do lose resolution of your potentiometer in the
  process.
*/

byte pitchChannel = 0xE0;

void pitchWheel() {  

  pitchVal = analogRead(joyV);
  int pitchValDiff = pitchVal - lastPitchVal;

  if (abs(pitchValDiff) > diff)
  {
    // construct 14 bit pitch bend value, see comment at bottom
    int modulation = map(pitchVal, 73, 955, -8000, 8000);
    modulation = constrain(modulation, -8000, 8000);
    unsigned int change = 0x2000 + modulation;  //  0x2000 == no Change
    byte low = change & 0x7F;
    byte high = change >> 7;

    midiEventPacket_t pitch = {0x0E, 0xE0 | pitchChannel, low, high};
    MidiUSB.sendMIDI(pitch);
    MidiUSB.flush();
    lastPitchVal = pitchVal;
  }
  delay(2);

}

/*
  Note on constructing the 14 bit pitch bend value:

  The pitch bend value is a 14-bit number (0-16383).
  0x2000 (8192) is the default / middle value.

  First byte is the event type (0x0E = pitch bend change).
  Second byte is the event type, combined with the channel.
  Third byte is the 7 least significant bits of the value.
  Fourth byte is the 7 most significant bits of the value.

*/
