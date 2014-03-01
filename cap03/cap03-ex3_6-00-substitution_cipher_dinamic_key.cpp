//2014.02.24 - 2014.02.25 Gustaf - CTG.


/* EXERCISE 3-6:
To make the ciphertext problem even more challenging, have your program
randomly generate the cipher array instead of a hard-coded const array.

Effectively, this means placing a random character in each element of the array.

  Remember that you can’t substitute a letter for itself. So the first
  element can’t be A, and you can’t use the same letter for two substitutions—
  that is, if the first element is S, no other element can be S.



=== (VERY HIGH LEVEL) PLAN ===

OK - Function to get a random integer given a range. There are two ways:
  The old way - http://www.cplusplus.com/reference/cstdlib/rand/

  The modern way - http://www.cplusplus.com/reference/random/
    NOTE: Requieres to use the compiler option: -std=gnu++11


OK - Using the random number get a letter and eliminate it from an auxiliary array
and put it in the new array.



------ normal ------
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'


*/


#include <iostream>
#include <random>

using namespace std;



int main()
{
  cout << "Hello world - Linux Mint." << endl;

  const int ARRAY_SIZE = 26;
  char normalLetters[ARRAY_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                     , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                                   };


  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };


  cout << endl;
  return 0;
}
