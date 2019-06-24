int const NUM_DIGITS = 4;

void setDigitValue(int value)
{
  const int SEGMENT_TO_PIN[] = { 2, 3, 4, 5, 6, 7, 8 };

  switch (value)
  {
  case 0:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], LOW);
    digitalWrite(SEGMENT_TO_PIN[5], LOW);
    digitalWrite(SEGMENT_TO_PIN[6], HIGH);
    break;

  case 1:
    digitalWrite(SEGMENT_TO_PIN[0], HIGH);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], HIGH);
    digitalWrite(SEGMENT_TO_PIN[4], HIGH);
    digitalWrite(SEGMENT_TO_PIN[5], HIGH);
    digitalWrite(SEGMENT_TO_PIN[6], HIGH);
    break;

  case 2:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], HIGH);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], LOW);
    digitalWrite(SEGMENT_TO_PIN[5], HIGH);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
    break;

  case 3:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], HIGH);
    digitalWrite(SEGMENT_TO_PIN[5], HIGH);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
    break;

  case 4:
    digitalWrite(SEGMENT_TO_PIN[0], HIGH);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], HIGH);
    digitalWrite(SEGMENT_TO_PIN[4], HIGH);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
    digitalWrite(SEGMENT_TO_PIN[5], LOW);
    break;

  case 5:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], HIGH);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], HIGH);
    digitalWrite(SEGMENT_TO_PIN[5], LOW);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
    break;

  case 6:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], HIGH);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], LOW);
    digitalWrite(SEGMENT_TO_PIN[5], LOW);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
    break;

  case 7:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], HIGH);
    digitalWrite(SEGMENT_TO_PIN[4], HIGH);
    digitalWrite(SEGMENT_TO_PIN[5], HIGH);
    digitalWrite(SEGMENT_TO_PIN[6], HIGH);
    break;

  case 8:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], LOW);
    digitalWrite(SEGMENT_TO_PIN[5], LOW);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
    break;

  case 9:
    digitalWrite(SEGMENT_TO_PIN[0], LOW);
    digitalWrite(SEGMENT_TO_PIN[1], LOW);
    digitalWrite(SEGMENT_TO_PIN[2], LOW);
    digitalWrite(SEGMENT_TO_PIN[3], LOW);
    digitalWrite(SEGMENT_TO_PIN[4], HIGH);
    digitalWrite(SEGMENT_TO_PIN[5], LOW);
    digitalWrite(SEGMENT_TO_PIN[6], LOW);
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

  const int DIGIT_TO_PIN[] = { 13, 12, 11, 10 };
  digitalWrite(DIGIT_TO_PIN[index], on ? HIGH : LOW);
}

void displayValue(int value)
{
  if (value < 0)
    value = 0;
  else if (value > 9999)
    value =  9999;

  if (value == 0)
  {
    setDigitValue(0);
    switchOnDigit(NUM_DIGITS -1);
    switchOffDigit(NUM_DIGITS -1);
    return;
  }

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