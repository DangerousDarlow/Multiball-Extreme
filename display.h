// Set 7 segment display digit value. All enabled digits will display the same value.
void setDigitValue(int value);

// Switch on a digit. An index of 0 is the most significant digit. An index of 4 is the least significant digit.
void switchOnDigit(int index);

// Switch off a digit. An index of 0 is the most significant digit. An index of 4 is the least significant digit.
void switchOffDigit(int index);

// Switch on or off a digit. An index of 0 is the most significant digit. An index of 4 is the least significant digit.
void switchOnOrOffDigit(int index, bool on);

// Display a value between 0 and 9999 inclusive
void displayValue(int value);