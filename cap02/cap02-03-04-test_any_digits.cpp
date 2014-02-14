//2014.01.21 Gustaf - CTG.

/*
At this point, we could easily expand the code to handle six-digit num-
bers or numbers with fewer digits. The pattern is clear: If the next character
is another digit, multiply the running total by 10 before adding the integer
digit value of the character. 

With this understanding, we can write a loop to handle a number of any length.
*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  cout << "Enter a number of any length: ";

  char digitChar = cin.get();
  int number = (digitChar - '0');

  digitChar = cin.get();
  while (digitChar != 10) { /*Check for the ENTER key.*/
    number = (number * 10) + (digitChar - '0');
    
    digitChar = cin.get();
  }
  cout << "Numbered entered: " << number << "\n";


  return 0;
}
