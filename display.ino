#include "display.h"

int const SENSORPIN = 9;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(SENSORPIN, INPUT);

  // Turn on pullup
  digitalWrite(SENSORPIN, HIGH);
}

int goals = 0;
int sensorCurrentValue = HIGH;
int sensorPreviousValue = HIGH;

void loop()
{
  sensorCurrentValue = digitalRead(SENSORPIN);
  if (sensorCurrentValue != sensorPreviousValue)
  {
    if (sensorCurrentValue == LOW)
      ++goals;
    
    sensorPreviousValue = sensorCurrentValue;
  }

  displayValue(goals);
}