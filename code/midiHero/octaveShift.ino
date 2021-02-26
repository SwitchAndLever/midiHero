/*
  Shifts the output one octave up or down

  Detects if the state of the two bridge buttons has changed and
  adds or subtracts 12 accordingly, which transposes (shifts) the 
  output one full octave up or down the scale.
*/

const uint8_t transpose = 12;

void octaveShift() {

  if (plusVal != lastPlusVal) {
    if (plusVal == 0) {
      octaveShiftVal = octaveShiftVal + transpose;
    }
    delay(2); // for stability
  }
  lastPlusVal = plusVal;

  if (bridgeVal != lastBridgeVal) {
    if (bridgeVal == 0) {
      octaveShiftVal = octaveShiftVal - transpose;
    }
    delay(2);
  }
  lastBridgeVal = bridgeVal;

}
