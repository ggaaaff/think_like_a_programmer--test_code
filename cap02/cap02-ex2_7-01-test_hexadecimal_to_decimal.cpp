//2014.02.05 Gustaf - CTG.


/*
=== PLAN ===

OK - Convert hexadecimal to decimal.
  OK - Numbers with digits: 0123456789.
  OK - Function that convert the input char in a number.
  OK - Numbers with letters: ABCDEF or abcdef.
   - TO DO - Catch the error when using letters not allowed.

*/


#include <iostream>

using std::cin;
using std::cout;


/* Based in: cap02-ex2_6-01-binary_to_decimal.cpp
*/

int charToNumber(char digitChar)
{
  switch (digitChar)
  {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    return (digitChar - '0');
    break;


  case 'A':
  case 'a':
    return 10;
    break;

  case 'B':
  case 'b':
    return 11;
    break;

  case 'C':
  case 'c':
    return 12;
    break;

  case 'D':
  case 'd':
    return 13;
    break;

  case 'E':
  case 'e':
    return 14;
    break;

  case 'F':
  case 'f':
    return 15;
    break;

  default: cout << digitChar << "  character not allowed!! \n";
    return -1;
    break;
  }


}


int main()
{
  cout << "CONVERT hexadecimal to decimal. \n";
  cout << "Enter a hexadecimal number of any length: ";

  char digitChar = cin.get();
  int number = charToNumber(digitChar);

  digitChar = cin.get();
  while (digitChar != 10)   /*Check for the ENTER key.*/
  {
    number = (number * 16) + charToNumber(digitChar); /*Trick to change from base 16*/

    digitChar = cin.get();
  }
  cout << "Numbered entered: " << number << "\n";


  cout << "\n";
  return 0;
}
