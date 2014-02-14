//2014.01.27 Gustaf - CTG.

/*
Verifing the C++ code found in this page:
http://en.wikipedia.org/wiki/International_Standard_Book_Number#ISBN-13_check_digit_calculation

*/


#include <iostream>
#include <string>

using namespace std;
// using std::cin;
// using std::cout;


bool is_valid_isbn13(char digits[13])
{
  /*Verifiy the whole 13 digits*/
  int i, check=0;
  for (i=0; i<13; i+=2) /*odd positions*/
    check += digits[i];

  for (i=1; i<12; i+=2) /*even positions*/
    check += 3*digits[i];

  return (check % 10) == 0;
}

int main()
{
  cout << "13-digit ISBN code found in Wikipedia. \n";
  char digitStr[13] = {'9','7','8','0','3','0','6','4','0','6','1','5','7'};
  cout << is_valid_isbn13(digitStr);

  cout << "\n";
  return 0;
}

