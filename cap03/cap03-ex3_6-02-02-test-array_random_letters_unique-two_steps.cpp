//2014.02.27 Gustaf - CTG.


/* OBJECTIVE :

Get a random array of letters.
But they can't be repeated.



=== PLAN ===

- Have an array that reflects the letters available to choose from.
  OK - Test the steps necessary to build the loop.


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

  char leftLetters[ARRAY_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                   , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                                 };


  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };


  srand(time(NULL)); //seed
  int randomNumber = 0;
  int countLetter = 0;



  //Get a new letter - THE FIRST
  //-----------------------------
  cout << "GET THE FIRST LETTER" << endl; //debug


  ++countLetter;
  randomNumber = 0 + rand() % 26;
  substitutionLetters[0] = leftLetters[randomNumber];

  cout << leftLetters[randomNumber] << endl; //debug

  leftLetters[randomNumber] = '#'; //the letter is no longer available.


  //Move the available letters to a temporary array
  char auxArray[ARRAY_SIZE - countLetter];
  int j = 0;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    if ( leftLetters[i] != '#')
    { 
      auxArray[j] = leftLetters[i];
      j++;
    }
  }

  //Output for debug
  for (int i = 0; i < (ARRAY_SIZE); ++i) //debug
  {
    cout << leftLetters[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < (ARRAY_SIZE - countLetter); ++i) //debug
  {
    cout << auxArray[i] << " ";
  }
  cout << endl;
  cout << endl;


  //Update the array with the available letters
  for (int i = 0; i < (ARRAY_SIZE); ++i)
  {
    leftLetters[i] = auxArray[i];

    if (i >= (ARRAY_SIZE - countLetter))
    {
      leftLetters[i] = '#';
    }
  }



  //Output DEBUG
  for (int i = 0; i < countLetter; ++i)
  {
    cout << substitutionLetters[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < (ARRAY_SIZE); ++i)
  {
    cout << leftLetters[i] << " ";
  }
  cout << endl;
  cout << endl;



  //Get a new letter - THE SECOND
  //------------------------------
  cout << "GET THE SECOND LETTER" << endl; //debug

  ++countLetter;
  randomNumber = 0 + rand() % (25 - 0);
  substitutionLetters[1] = leftLetters[randomNumber];

  cout << leftLetters[randomNumber] << endl; //debug

  leftLetters[randomNumber] = '#'; //the letter is no longer available.


  //Move the available letters to a temporary array
  char auxArray2[ARRAY_SIZE - countLetter];
  j = 0;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    if ( leftLetters[i] != '#')
    { 
      auxArray2[j] = leftLetters[i];
      j++;
    }
  }

  //Output for debug
  for (int i = 0; i < (ARRAY_SIZE); ++i) //debug
  {
    cout << leftLetters[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < (ARRAY_SIZE - countLetter); ++i) //debug
  {
    cout << auxArray2[i] << " ";
  }
  cout << endl;
  cout << endl;


  //Update the array with the available letters
  for (int i = 0; i < (ARRAY_SIZE); ++i)
  {
    leftLetters[i] = auxArray2[i];

    if (i >= (ARRAY_SIZE - countLetter))
    {
      leftLetters[i] = '#';
    }
  }



  //Output DEBUG
  for (int i = 0; i < countLetter; ++i)
  {
    cout << substitutionLetters[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < (ARRAY_SIZE); ++i)
  {
    cout << leftLetters[i] << " ";
  }
  cout << endl;




/*
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    randomNumber = 0 + rand() % (25 - 0);

    // substitutionLetters[i] = normalLetters[randomNumber];
  }

  //Output
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    // cout << substitutionLetters[i] << " ";
  }
*/

  cout << endl;
  return 0;
}
