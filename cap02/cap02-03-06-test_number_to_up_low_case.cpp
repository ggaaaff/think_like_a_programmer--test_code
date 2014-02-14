//2014.01.21 Gustaf - CTG.


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  int number;
  char outputCharacter;

  cout << "Enter a number 1-26 (to output in uppercase letter): ";
  cin >> number;
  outputCharacter = number + ('A' - 1);
  cout << "Equivalent symbol: " << outputCharacter << "\n" << "\n";


  cout << "Enter a number 1-26 (to output in lowercase letter): ";
  cin >> number;
  outputCharacter = number + ('a' - 1);
  cout << "Equivalent symbol: " << outputCharacter << "\n";


  return 0;
}


  