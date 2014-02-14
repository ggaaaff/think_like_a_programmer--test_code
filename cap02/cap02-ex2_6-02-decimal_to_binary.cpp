//2014.01.31 Gustaf - CTG.


/*

http://en.wikipedia.org/wiki/Binary_number#Decimal
The number is divided by two, and the remainder is the least-significant bit. 
The (integer) result is again divided by two, its remainder is the next least significant bit. 
This process repeats until the quotient becomes zero.


9 / 2      = 4,5 {get the integer} = 4
9 module 2 = 1 {last bit}

4 / 2      = 2
4 module 2 = 0 { bit}

2 / 2      = 1 
2 module 2 = 0 { bit}

1 / 2      = 0,5 {get the integer} = 0   quotient
1 module 2 = 1 {first bit}    remainder

==> 1001


PLAN
==================================

OK - Get information to remember the rules of convertions.

OK - Convert decimal to binary, an example.
 - Conversion code.

 - Experiment with recursion.



*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{  cout << "\n";

  cout << "CONVERT binary to decimal. \n";
  cout << "Enter a decimal number of any length: \n";

  int numDecimal = -1;
  int numQuotient = -1;
  int numRemainder = -1;

  cin >> numDecimal;
  numQuotient = numDecimal;
  cout << "\n";
  do
  {
    /*NOTE: this order is important, Remainder then quotient.*/
    numRemainder = numQuotient % 2;
    numQuotient  = numQuotient / 2; 

    // cout << numQuotient << "\n";
    cout << numRemainder << "\n";
  } while (numQuotient != 0);


  cout << "\n";
  return 0;
}
