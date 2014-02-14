//2014.01.22 Gustaf - CTG.


/*

PROBLEM: DECODE A MESSAGE

A message has been encoded as a text stream that is to be read character by charac-
ter. The stream contains a series of comma-delimited integers, each a positive number
capable of being represented by a C++ int. However, the character represented by
a particular integer depends on the current decoding mode. There are three modes:
uppercase, lowercase, and punctuation.

In uppercase mode, each integer represents an uppercase letter: The integer
modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an input
value of 143 in uppercase mode would yield the letter H because 143 modulo 27 is
8 and H is the eighth letter in the alphabet.

The lowercase mode works the same but with lowercase letters; the remainder of
dividing the integer by 27 represents the lowercase letter (1 = a and so on). So an
input value of 56 in lowercase mode would yield the letter b because 57 modulo 27
is 2 and b is the second letter in the alphabet.
In punctuation mode, the integer is instead considered modulo 9, with the inter-
pretation given by Table 2-3 below. So 19 would yield an exclamation point because
19 modulo 9 is 1.

At the beginning of each message, the decoding mode is uppercase letters. Each
time the modulo operation (by 27 or 9, depending on mode) results in 0, the decod-
ing mode switches. If the current mode is uppercase, the mode switches to lowercase
letters. If the current mode is lowercase, the mode switches to punctuation, and if it is
punctuation, it switches back to uppercase.


TEST
Original input:
18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10

Decoded message:
Right? Yes!


*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{

  char digitChar;
  int number;
  char outputCharacter;

  enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
  modeType mode = UPPERCASE;;


  cout << "Enter comma separated numbers: " << "\n";
  do {
    /*CHAR TO VALUE - INPUT COMMA SEPARATED */
    digitChar = cin.get();
    number = (digitChar - '0');
    
    digitChar = cin.get();
    while ((digitChar != 10) && (digitChar != ',')) { /*Check for EOL and comma*/
      number = number * 10 + (digitChar - '0');

      digitChar = cin.get();
    } /* var "number" has the value to decode */


    /*DECODE ONE VALUE AT A TIME*/
    switch (mode)
    {
    case UPPERCASE:
       /*decoding*/
      number = number % 27;
      outputCharacter = number + ('A' - 1); 

       /*switching mode*/
      if (number == 0)
      {
        mode = LOWERCASE;
        continue;
      }
      break;

    case LOWERCASE:
      /*decoding*/
      number = number % 27;
      outputCharacter = number + ('a' - 1);

       /*switching mode*/
      if (number == 0)
      {
        mode = PUNCTUATION;
        continue;
      }
      break;

    case PUNCTUATION:
      /*decoding*/
      number = number % 9;
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
  
       /*switching mode*/
      if (number == 0) 
      {
        mode = UPPERCASE;
        continue;
      }
      break;

    }//end switch


    /*show partial result*/
    cout << outputCharacter;

  } while (digitChar != 10); /*until EOL*/
  cout << "\n";



  return 0;
}





