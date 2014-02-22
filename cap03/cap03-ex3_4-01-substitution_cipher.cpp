//2014.02.21 Gustaf - CTG.


/* EXERCISE 3-4:
Here’s a variation on the array of const values.


Write a program for creating a substitution cipher problem.

  In a substitution cipher problem, all messages are made of uppercase letters and punctuation.
  The original message is called the plaintext, and you create the ciphertext
  by substituting each letter with another letter (for example, each C could become an X).

For this problem, hard-code a const array of 26 char elements for the cipher, and have your
program read a plaintext message and output the equivalent ciphertext.



=== PLAN ===

OK - Normal array of 26 elements.
{   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
  , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
}

- Function to cipher a single character.
  - Transform the char input from char to a number between 1 and 26.

- Accept input in upper and lower case.
- If it is an invalid character convert it to a space.

- Do the test with the normal array of letters.
- Do the test with the changed array of letters.



A 65    a 97
B 66    b 98
C 67    c 99
D 68    d 100
E 69    e 101
.       .
.       .
.       .
W 87    w 119
X 88    x 120
Y 89    y 121
Z 90    z 122




*/


#include <iostream>
#include <string>

using namespace std;


char cipherCharacter (char charInput)
{
  char cipherArray[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                          , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                         };

    int number = charInput;
    if (number >= 65 || number <= 90)
    {
      /* code */
    } else if (number >= 97 || number <= 122)
    {
      /* code */
    } else {
      //Character invalid.

    }

  return  cipherArray[ number + ('A' - 1) ];

}

int number;




int main()
{
  cout << "Substitution cipher." << endl;

  cout << "Enter the text to convert (valid letters in english)." << endl;



  char digitChar = cin.get();
  while (digitChar != 10)   /*Check for the ENTER key.*/
  {


    cout << digitChar << " ";

    int number = digitChar;
    cout << number << endl;


    digitChar = cin.get();
  }




  cout << endl;
  return 0;
}
