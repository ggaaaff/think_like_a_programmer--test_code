//2014.02.25 - 2014.02.27 Gustaf - CTG.


/* OBJECTIVE :

Get a new array filled with random letters.
Does not matter if they are repeated.


=== PLAN ===

OK - Generate random numbers.
OK - Fill in the new array.

*/



#include <iostream>
#include <cstdlib>

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

  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    int randomNumber = 0 + rand() % (25 - 0);

    substitutionLetters[i] = normalLetters[randomNumber];
  }

  //Output
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << substitutionLetters[i] << " ";
  }


  cout << endl;
  return 0;
}
