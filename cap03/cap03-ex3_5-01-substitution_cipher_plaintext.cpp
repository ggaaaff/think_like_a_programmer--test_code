//2014.02.23 Gustaf - CTG.


/* EXERCISE 3-5:
Have the previous program (3-4)
convert the ciphertext back to the plaintext to verify the encoding and decoding.



=== PLAN ===

OK- Capture the ciphertext in a vector.
OK - Pass the vector through the cipher function again.

OK- Generate two arrays: where number 3 depends on the correspondence between 1 and 2.
1: 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'  normal

2: 'G', 'Q', 'M', 'J', 'W', 'P', 'U', 'I', 'A', 'O', 'L', 'T', 'C', 'R', 'F', 'K', 'B', 'Y', 'E', 'X', 'N', 'D', 'Z', 'S', 'V', 'H'  to cipher

3: 'I', 'Q', 'M', 'V', 'S', 'O', 'A', 'Z', 'H', 'D', 'P', 'K', 'C', 'U', 'J', 'F', 'B', 'N', 'X', 'L', 'G', 'Y', 'E', 'T', 'R', 'W'  to plain


Example of the logic:
The A in array ONE is replaced by G in array TWO, 
then in array THREE in the position (index) for G, we put an A.
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;


char cipherCharacter (char charInput, int mode)
{
  /*  Valid values of variable mode:
      1 : to cipher.
      2 : to decipher.
  */

  char cipherArray[26] = {'G', 'Q', 'M', 'J', 'W', 'P', 'U', 'I', 'A', 'O', 'L', 'T', 'C'
                          , 'R', 'F', 'K', 'B', 'Y', 'E', 'X', 'N', 'D', 'Z', 'S', 'V', 'H'
                         };
  char toPlaintextArray[26] = {'I', 'Q', 'M', 'V', 'S', 'O', 'A', 'Z', 'H', 'D', 'P', 'K', 'C'
                               , 'U', 'J', 'F', 'B', 'N', 'X', 'L', 'G', 'Y', 'E', 'T', 'R', 'W'
                              };

  int number = charInput;
  if (number >= 65 && number <= 90)
  {
    //Upper case letters
    number = number % 65;
  }
  else if (number >= 97 && number <= 122)
  {
    //Lower case letters
    number = number % 97;
  }
  else
  {
    //Invalid character
    return '@';
  }

  if (mode == 1)
  {
    return cipherArray[ number ];
  }
  else if (mode == 2)
  {
    return toPlaintextArray[ number ];
  }


}



int main()
{
  cout << "Substitution cipher and decipher." << endl;

  vector<char> encodedData;
  encodedData.reserve(15);

  vector<char> decodedData;
  decodedData.reserve(15);


  cout << "Enter the text to convert (valid english letters)." << endl;
  char digitChar = cin.get();
  while (digitChar != 10)   /*Check for the ENTER key.*/
  {
    // cout << cipherCharacter(digitChar);
    encodedData.push_back( cipherCharacter(digitChar, 1) ); //To ciphertext

    digitChar = cin.get();
  }


  //Output ciphertext
  for (int i = 0; i < encodedData.size(); ++i)
  {
    cout << encodedData[i];
    decodedData.push_back( cipherCharacter( encodedData[i], 2 ) ); //To plaintext
  }
  cout << endl;


  //Output plaintext
  for (int i = 0; i < decodedData.size(); ++i)
  {
    cout << decodedData[i];
  }

  cout << endl;
  return 0;
}
