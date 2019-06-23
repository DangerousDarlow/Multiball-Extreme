int const NUM_DIGITS = 4;

void setDigitValue(int value)
{
  switch (value)
  {
  case 0:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    break;

  case 1:
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    break;

  case 2:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    break;

  case 3:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    break;

  case 4:
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    break;

  case 5:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;

  case 6:
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;

  case 7:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    break;

  case 8:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;

  case 9:
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    break;
  }
}

void switchOnDigit(int index)
{
  switchOnOrOffDigit(index, true);
}

void switchOffDigit(int index)
{
  switchOnOrOffDigit(index, false);
}

void switchOnOrOffDigit(int index, bool on)
{
  if (index < 0)
    index = 0;
  else if (index > NUM_DIGITS -1)
    index = NUM_DIGITS -1;

  const int DIGIT[] = { 11, 10, 9, 8 };
  digitalWrite(DIGIT[index], on ? HIGH : LOW);
}

void displayValue(int value)
{
  if (value < 0)
    value = 0;
  else if (value > 9999)
    value =  9999;

  uint8_t digits[NUM_DIGITS];
  memset(digits, 0, NUM_DIGITS);

  for (int index = 0; index < NUM_DIGITS; ++index)
  {
    const int digitIndexFromLeft = NUM_DIGITS - index - 1;
    digits[digitIndexFromLeft] = value % 10;
    if (value < 10)
      break;

    value /= 10;
  }

  bool allZero = true;
  for (int index = 0; index < NUM_DIGITS; ++index)
  {
    if (digits[index] == 0 && allZero)
      continue;

    allZero = false;

    setDigitValue(digits[index]);
    switchOnDigit(index);
    switchOffDigit(index);
  }
}