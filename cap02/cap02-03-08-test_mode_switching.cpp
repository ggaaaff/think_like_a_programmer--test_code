//2014.01.21 Gustaf - CTG.


#include <iostream>

using std::cin;
using std::cout;


int main()
{

  enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
  int number;
  modeType mode = UPPERCASE;
  cout << "Enter some numbers (separated by a space) ending with -1: ";
  do
  {
    cin >> number;
    cout << "Number read: " << number;
    switch (mode)
    {
    case UPPERCASE:
      number = number % 27;
      cout << ". Modulo 27: " << number << ". ";
      if (number == 0)
      {
        cout << "Switch to LOWERCASE";
        mode = LOWERCASE;
      }
      break;
    case LOWERCASE:
      number = number % 27;
      cout << ". Modulo 27: " << number << ". ";
      if (number == 0)
      {
        cout << "Switch to PUNCTUATION";
        mode = PUNCTUATION;
      }
      break;
    case PUNCTUATION:
      number = number % 9;
      cout << ". Modulo 9: " << number << ". ";
      if (number == 0)
      {
        cout << "Switch to UPPERCASE";
        mode = UPPERCASE;
      }
      break;
    }
    cout << "\n";
  }
  while (number != -1);

  return 0;
}

