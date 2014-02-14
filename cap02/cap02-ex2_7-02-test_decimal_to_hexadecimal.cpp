//2014.02.06 Gustaf - CTG.


/*


PLAN
==================================

OK - Convert decimal to hexadecimal.



*/


#include <iostream>

using std::cin;
using std::cout;


/*BASED IN: cap02-ex2_6-02-decimal_to_binary.cpp
*/

int main()
{  cout << "\n";

  cout << "CONVERT decimal to hexadecimal. \n";
  cout << "Enter a decimal number of any length: \n";

  int numDecimal = -1;
  int numQuotient = -1;
  int numRemainder = -1;
  char hexaVal[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

  cin >> numDecimal;
  numQuotient = numDecimal;
  cout << "\n";
  do
  {
    /*NOTE: this order is important, Remainder then quotient.*/
    numRemainder = numQuotient % 16;
    numQuotient  = numQuotient / 16; 

    cout << hexaVal[numRemainder] << "\n";
  } while (numQuotient != 0);


  cout << "\n";
  return 0;
}
