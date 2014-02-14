//2014.01.21 Gustaf - CTG.

/*
PROBLEM: READING A NUMBER WITH THREE OR FOUR DIGITS
Write a program to read a number character by character and convert it to an inte-
ger, using just one char variable and one int variable. The number will have either
three or four digits.
*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  cout << "Enter a three-digit or four-digit number: ";

  char digitChar = cin.get();
  int number = (digitChar - '0') * 100;

  digitChar = cin.get();
  number += (digitChar - '0') * 10;

  digitChar = cin.get();
  number += (digitChar - '0');

  digitChar = cin.get();
  if (digitChar == 10) { /*Check for the ENTER key.*/
    cout << "Numbered entered: " << number << "\n";
  } else {
    number = (number * 10) + (digitChar - '0'); //Trick to get the 4th digit number.
    cout << "Numbered entered: " << number << "\n";
  }


  return 0;
}
