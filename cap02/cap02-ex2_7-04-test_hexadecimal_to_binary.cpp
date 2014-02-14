//2014.02.06 Gustaf - CTG.


/*
=== PLAN ===

OK - Convert hexadecimal to binary.


*/

#include <iostream>
#include <string>

using namespace std;



int charToBinary(char digitChar)
{
  string charBinary[] = { "0000", "0001", "0010", "0011",
                          "0100", "0101", "0110", "0111",
                          "1000", "1001", "1010", "1011",
                          "1100", "1101", "1110", "1111"
                        };

  switch (digitChar)
  {
  case '0': cout << charBinary[0] << " "; break;
  case '1': cout << charBinary[1] << " "; break;
  case '2': cout << charBinary[2] << " "; break;
  case '3': cout << charBinary[3] << " "; break;
  case '4': cout << charBinary[4] << " "; break;
  case '5': cout << charBinary[5] << " "; break;
  case '6': cout << charBinary[6] << " "; break;
  case '7': cout << charBinary[7] << " "; break;
  case '8': cout << charBinary[8] << " "; break;
  case '9': cout << charBinary[9] << " "; break;

  case 'A':
  case 'a':
    cout << charBinary[10] << " "; break;

  case 'B':
  case 'b':
    cout << charBinary[11] << " "; break;

  case 'C':
  case 'c':
    cout << charBinary[12] << " "; break;

  case 'D':
  case 'd':
    cout << charBinary[13] << " "; break;

  case 'E':
  case 'e':
    cout << charBinary[14] << " "; break;

  case 'F':
  case 'f':
    cout << charBinary[15] << " "; break;

  }

}


int main()
{
  cout << "CONVERT hexadecimal to binary. \n";
  cout << "Enter an hexadecimal number of any length: ";

  char digitChar = cin.get();

  while (digitChar != 10)   /*Check for the EOL key.*/
  {
    charToBinary(digitChar);
    digitChar = cin.get();
  }

  cout << "\n";
  return 0;
}
