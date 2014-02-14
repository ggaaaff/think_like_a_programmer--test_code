//2014.01.21 Gustaf - CTG.


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  int number;
  char outputCharacter;

  cout << "Enter a number 1-8 (to output punctuation): ";
  cin >> number;
  switch (number) {
    case 1: outputCharacter = '!'; break;
    case 2: outputCharacter = '?'; break;
    case 3: outputCharacter = ','; break;
    case 4: outputCharacter = '.'; break;
    case 5: outputCharacter = ' '; break;
    case 6: outputCharacter = ';'; break;
    case 7: outputCharacter = '"'; break;
    case 8: outputCharacter = '\''; break;
  }
  
  cout << "Equivalent symbol: " << outputCharacter << "\n";

  return 0;
}
