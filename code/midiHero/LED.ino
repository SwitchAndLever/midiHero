/*
  Fades LEDs in and out

  Uses the SoftPWM library as LEDs were connected on non PWM pins.
  If you connect your LEDs on PWM pins you do not need this library.

  Either way avoid using delay() to control the LEDs as this will
  severely slow down the sketch and making button reads unresponsive.
*/

int itr = 0;
int breathe_delay = 0;   // delay between steps, 0 = run as fast as possible
unsigned long breathe_time = millis();

void LEDs(uint8_t LEDrate) { // higher 'LEDrate' value = faster fading

  if ( (breathe_time + breathe_delay) < millis() ) {
    breathe_time = millis();
    float val = (exp(sin(itr / 2000.0 * PI * 10)) - 0.36787944) * 108.0;  // breathing fade math
    SoftPWMSet(led1, val);  // PWM
    val = map(val, 0, 255, 255, 0); // invert 'val' to fade up/down each LED individually
    SoftPWMSet(led2, val);  // PWM
    itr = itr + LEDrate;
  }

}
