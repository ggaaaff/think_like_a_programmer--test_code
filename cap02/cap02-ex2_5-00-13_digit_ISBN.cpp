
//2014.01.27 Gustaf - CTG.


/* PROBLEM 2.5
If you like the Luhn formula problem, try writing a program for a different
check-digit system, like the 13-digit ISBN system. The program could take an
identification number and verify it or take a number without its check digit
and generate the check digit.

*/


/* INFORMATION


http://en.wikipedia.org/wiki/Check_digit

ISBN 13 (in use January 2007) is equal to the EAN-13 code found underneath a book's barcode. 
Its check digit is generated the same way as the UPC except that the even digits are 
multiplied by 3 instead of the odd digits.

    UPC
    The final digit of a Universal Product Code is a check digit computed as follows:
      Add the digits (up to but not including the check digit) in the odd-numbered positions (first, third, fifth, etc.) together and multiply by three.
      Add the digits (up to but not including the check digit) in the even-numbered positions (second, fourth, sixth, etc.) to the result.
      Take the remainder of the result divided by 10 (modulo operation) and subtract this from 10 to derive the check digit.



http://en.wikipedia.org/wiki/International_Standard_Book_Number
    There are algorithms implemented.

    The calculation of an ISBN-13 check digit begins with the first 12 digits of the thirteen-digit ISBN (thus excluding the check digit itself). 
    Each digit, from left to right, is alternately multiplied by 1 or 3, 
    then those products are summed modulo 10 to give a value ranging from 0 to 9. 
    Subtracted from 10, that leaves a result from 1 to 10. 
    NOTE: A zero (0) replaces a ten (10), so, in all cases, a single check digit results.

Example: 978-0-306-40615-?
97 80 30 64 06 15
(9*1)+(7*3) +(8*1)+(0*3) +(3*1)+(0*3) +(6*1)+(4*3) +(0*1)+(6*3) +(1*1)+(5*3) = 93
93 mod 10 = 3
10 - 3 = 7 

9780306406157
9781593274245


==========================================
PLAN

OK - Investigate the 13-digit ISBN system.
OK - Make an example.

OK - Divide the problem of checking a 13-digit ISBN.
  OK - Capture the 13 digits.
  OK - Sum all digits. 
  OK - Multiply every other and sum all. AHEM except the last one!!
  OK - Substract from 10, the sum module of 10.
  OK - Display the check digit and verify that "10" becomes "0".

OK - Check (at the end) that have been introduced only 13 digits.


*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  cout << "Checking a 13-digit ISBN number.  \n";
  cout << "Introduce a 13 digit number (no symbols).  \n";

  char digitChar;
  int index = 1;
  int sum = 0;
  int numProduct = 0;
  int result = -1;
  int checkDigitTyped = -1;

  index = 1;
  digitChar = cin.get();
  while (digitChar != 10)  /*check EOL*/
  {
    
    if ( index <= 12 ) /*Exclude from the sum the check digit*/
    {
      if (index % 2 == 0) {  /*check even or odd*/
        numProduct = 3 * (digitChar - '0');
      } else {
        numProduct = 1 * (digitChar - '0');
      }
      sum = sum + numProduct;
    }

    digitChar = cin.get();
    index++;

    if (index == 13) /*Get the 13th digit typed*/
    {
      checkDigitTyped = (digitChar - '0');
    }
  }

  cout << "\n";
  // cout << "SUM: " << (sum) << "\n";

  if ((index -1) != 13) {
    cout << "ERROR introducing the exact number of digits. \n";
    cout << "Digits: " << (index -1) << "\n";
  } else {
    result = (10 - (sum % 10)); /*Get the preliminar check digit*/
    if (result == 10) { 
      result = 0; /*Transform the 10 to 0*/
    }
    cout << "CHECK DIGIT, TYPED      : " << checkDigitTyped << "\n";
    cout << "CHECK DIGIT, CALCULATED : " << result << "\n";

    if (result == checkDigitTyped) {
      cout << "The 13-digit number is correct. \n";
    } else {
      cout << "The 13-digit number is not correct. \n";
    }
  }

  cout << "\n";
  return 0;
}
