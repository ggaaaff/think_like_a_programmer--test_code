//2014.01.21 Gustaf - CTG.

/*
PROBLEM: READING A NUMBER WITH THREE OR FOUR DIGITS, FURTHER SIMPLIFIED
Write a program to read a number character by character and convert it to an inte-
ger, using just one char variable and two int variables. The number will have either
three or four digits.

*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  cout << "Enter a three-digit or four-digit number: ";

  char digitChar = cin.get();
  int threeDigitNumber = (digitChar - '0') * 100;
  int fourDigitNumber = (digitChar - '0') * 1000;

  digitChar = cin.get();
  threeDigitNumber += (digitChar - '0') * 10;
  fourDigitNumber += (digitChar - '0') * 100;

  digitChar = cin.get();
  threeDigitNumber += (digitChar - '0');
  fourDigitNumber += (digitChar - '0') * 10;

  digitChar = cin.get();
  if (digitChar == 10) { /*Check for the ENTER key.*/
    cout << "Numbered entered: " << threeDigitNumber << "\n";
  } else {
    fourDigitNumber += (digitChar - '0');
    cout << "Numbered entered: " << fourDigitNumber << "\n";
  }


  return 0;
}



  

