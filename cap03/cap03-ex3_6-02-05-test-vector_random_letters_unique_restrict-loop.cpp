//2014.03.03 Gustaf - CTG.



/* OBJECTIVE :

Get a random array of letters.
But they can't be repeated.

  Remember that you can’t substitute a letter for itself. So the first element can’t be A.

Use a vector to see if the complexity of handling arrays is decreased.


------Information
http://www.cplusplus.com/reference/vector/vector/
Compared to the other dynamic sequence containers (deques, lists and forward_lists),
vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end.
For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others.




=== PLAN ===

TO DO- Use a vector for the available letters.
  FAIL - Use the function vector.erase()
         http://www.cplusplus.com/reference/vector/vector/erase/

*/




#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;

  const int ARRAY_SIZE = 26;
  char normalLetters[ARRAY_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                     , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                                   };

  //2014.03.01 NOTE: Moving the letter 'Z' eliminate the chance that it appear at the end of the final array.
  char availableLetters[ARRAY_SIZE] = { 'A', 'Z', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                        , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'
                                      };


  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };



  //Creating the vector.
  vector<char> availableLettersVector;
  availableLettersVector.reserve(ARRAY_SIZE);

  //Initialize vector.
  for (int i = 0; i < (ARRAY_SIZE); ++i)
  {
    availableLettersVector[i] = availableLetters[i];
  }




  int randomNumber = 0;
  int lowest = 0, highest = 0, range = 0;

  int countLetter = 0;
  int lettersAvailableCount = 0;

  char possibleLetter = '@'; //Initialized with invalid value.


  srand(time(NULL)); //seed - Keep it out of any loop.
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    ++countLetter;
    lettersAvailableCount = (ARRAY_SIZE - countLetter);

    highest = lettersAvailableCount;
    range = (highest - lowest) + 1; // This range decreases while the loop progress.

    cout << "GETTING THE LETTER NUMBER: " << countLetter << " - " << range << endl; //DEBUG


    // Testing possible letters
    possibleLetter = '@'; //Initialized with invalid value.
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
    
    //NOTE 2014.03.03 there is aproblen with the use of namespaces. I can't solve it with my actual knowledge of C++.
    availableLettersVector.erase(randomNumber); //the letter is no longer available.


    cout << endl << "Got the letter: " << possibleLetter  << endl; //DEBUG




//-------------------
/*
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
    }*/

//--------------



    //--- Output for DEBUG
    cout << "substitutionLetters: ";
    for (int i = 0; i < countLetter; ++i)
    {
      cout << substitutionLetters[i] << " ";
    }
    cout << endl;

    cout << "availableLettersVector: ";
    for (int i = 0; i < (ARRAY_SIZE); ++i)
    {
      cout << availableLettersVector[i] << " ";
    }
    cout << endl;
    cout << endl;
    //---


  }//-- main FOR end.



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
