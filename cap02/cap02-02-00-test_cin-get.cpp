//2014.01.17 Gustaf - CTG.

#include <iostream>

using std::cin;
using std::cout;


int main()
{
  char digit;
  cout << "Enter a one-digit number: ";
  cin >> digit;
  int sum = digit - '0';  //Truco para convertir el carácter a número.
  cout << "Is the sum of digits " << sum << "? \n";

  cout << "(CTRL+C ends infinite loop!!) Enter a number: ";
  //char digit;
  while (true) {
    digit = cin.get();
    cout << int(digit) << " ";
  }
    
  return 0;
}
