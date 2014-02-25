//2014.02.25 Gustaf - CTG.


/* OBJECTIVE :
Using the random number get a letter and eliminate it from an auxiliary array
and put it in the new array.



=== PLAN ===

-
-

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


  //Initialice array
  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    srand(time(NULL));
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
