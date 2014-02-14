//2014.01.21 Gustaf - CTG.


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  cout << "Enter comma separated numbers: " << "\n";
  char digitChar;
  do {
    digitChar = cin.get();
    int number = (digitChar - '0');
    
    digitChar = cin.get();
    while ((digitChar != 10) && (digitChar != ',')) { /*Check for EOL and comma*/
      number = number * 10 + (digitChar - '0');

      digitChar = cin.get();
    }

    cout << "Numbered entered: " << number << "\n";
  } while (digitChar != 10);


  return 0;
}


