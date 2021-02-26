/*
  Reads all buttons and assigns their values to variables
*/

void readButtons() {

  strumUpVal = digitalRead(strumUp);
  strumDownVal = digitalRead(strumDown);
  plusVal = digitalRead(plus);
  bridgeVal = digitalRead(bridge);
  emergencyVal = digitalRead(emergency);

}

// Read neck buttons
void readNeck() {

  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (digitalRead(buttons[i]) == LOW)
    {
      bitWrite(pressedButtons, i, 1);
      delay(10); // for debounce stability
    }
    else
      bitWrite(pressedButtons, i, 0);
  }

}
