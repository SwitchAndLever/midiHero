/*
  Reads horizontal joystick, assigns and outputs its value to mod wheel

  Checks last value and will only send a new value if the new value differs
  by more than 'diff' to avoid the slight noise which potentiometers can
  have at rest, so it doesn't constantly keep sending messages which slows
  down the sketch. If your potentiometer is very noisy this value may need
  increasing, though you do lose resolution of your potentiometer in the
  process.
*/

byte modChannel = 0xB0;

void modWheel() {

  modVal = analogRead(joyH);
  int modValDiff = modVal - lastModVal;

  if (abs(modValDiff) > diff)
  {
    int modulation = map(modVal, 935, 50, 0, 127);
    modulation = constrain(modulation, 0, 127);

    midiEventPacket_t mod = {0x0B, 0xB0 | modChannel, 01, modulation};
    MidiUSB.sendMIDI(mod);
    MidiUSB.flush();
    lastModVal = modVal;
  }
  delay(2);

}
