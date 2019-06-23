void setup()
{

  for (int pin = 0; pin < 12; ++pin)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void displayDigit(int value)
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

int getPositiveOutput(int digitIndexFromLeft)
{
  switch (digitIndexFromLeft)
  {
  case 0:
    return 11;

  case 1:
    return 10;

  case 2:
    return 9;

  case 3:
    return 8;
  }
}

void displayValue(int value)
{
  const int numDigits = 4;

  if (value == 0)
  {
    digitalWrite(getPositiveOutput(0), LOW);
    digitalWrite(getPositiveOutput(1), LOW);
    digitalWrite(getPositiveOutput(2), LOW);
    digitalWrite(getPositiveOutput(3), HIGH);
    displayDigit(0);
    return;
  }

  uint8_t digits[numDigits];
  memset(digits, 0, numDigits);

  for (int index = 0; index < numDigits; ++index)
  {
    const int digitIndexFromLeft = numDigits - index - 1;
    digits[digitIndexFromLeft] = value % 10;
    if (value < 10)
      break;

    value /= 10;
  }

  bool allZero = true;
  for (int index = 0; index < numDigits; ++index)
  {
    if (digits[index] == 0 && allZero)
    {
      digitalWrite(getPositiveOutput(index), LOW);
      continue;
    }

    allZero = false;

    digitalWrite(getPositiveOutput(index), HIGH);
    displayDigit(digits[index]);
  }
}

void loop()
{
  displayValue(0);
  delay(500);

  displayValue(1);
  delay(500);

  // displayValue(11);
  // delay(500);

  // displayValue(110);
  // delay(500);

  // displayValue(1000);
  // delay(500);
}