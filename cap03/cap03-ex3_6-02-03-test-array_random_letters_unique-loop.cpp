//2014.02.27 Gustaf - CTG.


/* OBJECTIVE :

Get a random array of letters.
But they can't be repeated.



=== PLAN ===

OK - Have an array that reflects the letters available to choose from.
OK - Get random letters from that array.


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

  char availableLetters[ARRAY_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                   , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                                 };


  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };


  srand(time(NULL)); //seed
  int randomNumber = 0;
  int lowest = 0, highest = 0, range = 0;

  int countLetter = 0;
  int lettersAvailableCount = 0;

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    ++countLetter;
    lettersAvailableCount = (ARRAY_SIZE - countLetter);

    highest = lettersAvailableCount;
    range = (highest - lowest) + 1;
    randomNumber = lowest + rand() % range;

    cout << "GETTING THE LETTER NUMBER: " << countLetter << " - " << availableLetters[randomNumber] << " - " << range << endl; //DEBUG

    substitutionLetters[ countLetter - 1 ] = availableLetters[randomNumber];
    availableLetters[randomNumber] = '#'; //the letter is no longer available.



    //Move the available letters to a temporary array
    char auxArray[lettersAvailableCount]; // Nice trick in C++, the dinamic creation.
    int j = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
      if ( availableLetters[i] != '#')
      {
        auxArray[j] = availableLetters[i];
        j++;
      }
    }

    //--- Output for DEBUG
    for (int i = 0; i < (ARRAY_SIZE); ++i) //DEBUG
    {
      cout << availableLetters[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < (lettersAvailableCount); ++i) //DEBUG
    {
      cout << auxArray[i] << " ";
    }
    cout << endl;
    cout << endl;
    //---


    //Update the array with the available letters
    for (int i = 0; i < (ARRAY_SIZE); ++i)
    {
      availableLetters[i] = auxArray[i];

      if (i >= (lettersAvailableCount))
      {
        availableLetters[i] = '#';
      }
    }


    //--- Output for DEBUG
    for (int i = 0; i < countLetter; ++i)
    {
      cout << substitutionLetters[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < (ARRAY_SIZE); ++i)
    {
      cout << availableLetters[i] << " ";
    }
    cout << endl;
    cout << endl;
    //---

  }



  cout << endl;
  cout << "The final array." << endl; //DEBUG
  for (int i = 0; i < countLetter; ++i)
  {
    cout << substitutionLetters[i] << " ";
  }
  cout << endl;


  cout << endl;
  return 0;
}
