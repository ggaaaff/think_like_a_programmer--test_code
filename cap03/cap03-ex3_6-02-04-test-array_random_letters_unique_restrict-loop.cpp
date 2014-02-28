//2014.02.27 Gustaf - CTG.


/* OBJECTIVE :

Get a random array of letters.
But they can't be repeated.

  Remember that you can’t substitute a letter for itself. So the first element can’t be A.

NOTE: This can create an infinite loop.
IF the last letter and the last slot available are the same.
 In fact I saw it twice in the test, here is a prove:

                  K J I V H X Y M E T S R B A P G O D W U C Q L F 
                  N Z # # # # # # # # # # # # # # # # # # # # # # # # 

                  GETTING THE LETTER NUMBER: 25 - 2
                  Possible letter (char - random number - lettersAvailableCount) N - 0 - 1
                  Letter (char - int - index) N - 78 - 13

                  Got the letter: N
                  # Z # # # # # # # # # # # # # # # # # # # # # # # # 
                  Z 

                  K J I V H X Y M E T S R B A P G O D W U C Q L F N 
                  Z # # # # # # # # # # # # # # # # # # # # # # # # # 

                  GETTING THE LETTER NUMBER: 26 - 1
                  Possible letter (char - random number - lettersAvailableCount) Z - 0 - 0
                  Letter (char - int - index) Z - 90 - 25
                  Letter collition - We CAN NOT try another letter.


                  Got the letter: Z
                  # # # # # # # # # # # # # # # # # # # # # # # # # # 


                  K J I V H X Y M E T S R B A P G O D W U C Q L F N Z 
                  # # # # # # # # # # # # # # # # # # # # # # # # # # 


                  The final array.
                  K J I V H X Y M E T S R B A P G O D W U C Q L F N Z 




=== PLAN ===

OK - Add restriction to get the actual letter.
OK - Resolve the infinite looops.


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



  int randomNumber = 0;
  int lowest = 0, highest = 0, range = 0;

  int countLetter = 0;
  int lettersAvailableCount = 0;

  char possibleLetter = '@';


  srand(time(NULL)); //seed - Keep it out of any loop.
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    ++countLetter;
    lettersAvailableCount = (ARRAY_SIZE - countLetter);

    highest = lettersAvailableCount;
    range = (highest - lowest) + 1; // This range decreases while the loop progress.

    cout << "GETTING THE LETTER NUMBER: " << countLetter << " - " << range << endl; //DEBUG


    // Testing possible letters
    possibleLetter = '@';
    while ( possibleLetter == '@'  )
    {
      randomNumber = lowest + rand() % range;
      possibleLetter = availableLetters[randomNumber];

      cout << "Possible letter (char - random number - lettersAvailableCount) " << possibleLetter << " - " << randomNumber << " - " << lettersAvailableCount << endl; // DEBUG


      // The possible letter can not be in the same index position as the normal letters
      int digitLetter = possibleLetter; // Cast from the char letter to the ASCII integer.
      int indexLetter = -1;
      if (digitLetter >= 65 && digitLetter <= 90)
      {
        //Upper case letters
        indexLetter = digitLetter % 65; // Convertion to an index in the normal array [0..25].
      }
      else
      {
        //Invalid character
        indexLetter = -1; // If the "availableLetters" array is misconfigured this could lead to an infinite loop.
        cout << "UNEXPECTED ERROR: the availableLetters array is misconfigured, IT REQUIRE (ENGLISH) UPPERCASE LETTERS." << endl; // ERROR
      }

      cout << "Letter (char - int - index) " << possibleLetter << " - " << digitLetter << " - " << indexLetter << endl; // DEBUG
      if ( (indexLetter == -1) || ( (countLetter - 1) == indexLetter) )
      {

        // If this is the last letter for the last slot (so there are no other possibilities),
        // then we have to stop the loop and violate this rule
        if (lettersAvailableCount == 0)
        {
          //This solve a potential infinite loop.
          cout << "Letter verification - We CAN NOT try another letter."  << endl << endl; // DEBUG
        }
        else
        {
          possibleLetter = '@';
          cout << "Letter collition - Will try another letter."  << endl << endl; // DEBUG
        }

      }

    }



    // We got the new letter
    substitutionLetters[ countLetter - 1 ] = possibleLetter;
    availableLetters[randomNumber] = '#'; //the letter is no longer available.

    cout << endl << "Got the letter: " << possibleLetter  << endl; //DEBUG


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
