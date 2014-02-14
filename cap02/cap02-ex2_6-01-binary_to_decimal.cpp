//2014.01.31 Gustaf - CTG.


/*
2-6. If you’ve learned about binary numbers and how to convert from decimal
to binary and the reverse, try writing programs to do those conversions with
unlimited length numbers (but you can assume the numbers are small
enough to be stored in a standard C++ int).


http://en.wikipedia.org/wiki/Binary_number#Counting_in_binary
Since binary is a base-2 system, each digit represents an increasing power of 2, with the rightmost digit representing 2^0, the next representing 2^1, then 2^2, and so on. To determine the decimal representation of a binary number simply take the sum of the products of the binary digits and the powers of 2 which they represent. For example, the binary number 100101 is converted to decimal form as follows:

100101(2) = [ ( 1 ) × 2^5 ] + [ ( 0 ) × 2^4 ] + [ ( 0 ) × 2^3 ] + [ ( 1 ) × 2^2 ] + [ ( 0 ) × 2^1 ] + [ ( 1 ) × 2^0 ]
100101(2) = [ 1 × 32 ] + [ 0 × 16 ] + [ 0 × 8 ] + [ 1 × 4 ] + [ 0 × 2 ] + [ 1 × 1 ]
100101(2) = 37(10)

To create higher numbers, additional digits are simply added to the left side of the binary representation.



PLAN
==================================

OK - Get information to remember the rules of convertions.

OK - Convert binary to decimal.

*/



#include <iostream>

using std::cin;
using std::cout;

/* Based in: cap02-03-04-test_any_digits.cpp
*/


int main()
{
  cout << "CONVERT binary to decimal. \n";
  cout << "Enter a binary number of any length: ";

  char digitChar = cin.get();
  int number = (digitChar - '0');

  digitChar = cin.get();
  while (digitChar != 10) { /*Check for the ENTER key.*/
    number = (number * 2) + (digitChar - '0'); /*Trick for change from base 2*/
    
    digitChar = cin.get();
  }
  cout << "Numbered entered: " << number << "\n";


  return 0;
}
