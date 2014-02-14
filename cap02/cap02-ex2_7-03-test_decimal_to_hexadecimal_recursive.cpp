//2014.02.06 Gustaf - CTG.


/*


PLAN
==================================

OK - Convert decimal to hexadecimal.



*/


#include <iostream>

using std::cin;
using std::cout;

/*BASED IN: cap02-ex2_6-03-decimal_to_binary_recursive.cpp
*/


void recur(int numQuotient)
{
  int numRemainder = -1;
  char hexaVal[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

  /*NOTE: this order is important, Remainder then quotient.*/
  numRemainder = numQuotient % 16;
  numQuotient  = numQuotient / 16; 

  if (numQuotient != 0)
    recur(numQuotient); /*recursive call*/

  cout << hexaVal[numRemainder];
}


int main()
{
  cout << "CONVERT decimal to hexadecimal. \n";
  cout << "Enter a decimal number of any length: \n";

  int numDecimal = -1;
  cin >> numDecimal;
  cout << "\n";
  recur(numDecimal);

  cout << "\n";
  return 0;
}
