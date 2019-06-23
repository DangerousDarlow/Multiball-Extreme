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
  displayValue(123);
}