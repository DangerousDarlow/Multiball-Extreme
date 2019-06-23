#include "display.h"

void setup()
{
  for (int pin = 0; pin < 12; ++pin)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop()
{
  displayValue(0);
  delay(500);

  displayValue(5);
  delay(500);

  displayValue(11);
  delay(500);

  displayValue(110);
  delay(500);

  displayValue(1000);
  delay(500);
}