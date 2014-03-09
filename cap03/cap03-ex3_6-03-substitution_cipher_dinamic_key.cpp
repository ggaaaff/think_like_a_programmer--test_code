//2014.03.09 Gustaf - CTG.


/* EXERCISE 3-6:
To make the ciphertext problem even more challenging, have your program
randomly generate the cipher array instead of a hard-coded const array.

Effectively, this means placing a random character in each element of the array.

  Remember that you can’t substitute a letter for itself. So the first
  element can’t be A, and you can’t use the same letter for two substitutions—
  that is, if the first element is S, no other element can be S.



=== PLAN ===

OK - Integrate all the work.

*/


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


/* BASED ON:
cap03-ex3_6-02-09-test-vector_random_letters_unique_restrict-function-switchDebug.cpp
cap03-ex3_4-01-substitution_cipher.cpp


*/


//Global variables.
const int ARRAY_SIZE = 26;

int countLetter;
int lettersAvailableCount;
//---



char checkValidPossibleLetter ( char possibleLetter, bool outputDebug )
{
  // Return a '@' if the check is invalid, otherwise the same input char.

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

  outputDebug ? cout << "Letter (char - int - index) " << possibleLetter << " - " << digitLetter << " - " << indexLetter << endl : false; // DEBUG
  if ( (indexLetter == -1) || ( (countLetter - 1) == indexLetter) )
  {

    // If this is the last letter for the last slot (so there are no other possibilities),
    // then we have to stop the loop and violate this rule
    if (lettersAvailableCount == 0)
    {
      //This solve a potential infinite loop.
      outputDebug ? cout << "Letter verification - We CAN NOT try another letter."  << endl << endl : false; // DEBUG
    }
    else
    {
      possibleLetter = '@';
      outputDebug ? cout << "Letter collition - Will try another letter."  << endl << endl : false; // DEBUG
    }

  }


  return possibleLetter;
} //-- function



void generateRandomArray(char *randomArrayLetters, bool outputDebug)
{
  char normalLetters[ARRAY_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                     , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                                   };

  //2014.03.04 NOTE: Moving the letter 'Z' REDUCE the chance that it appear at the end of the final array.
  char availableLetters[ARRAY_SIZE] = { 'A', 'Z', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
                                        , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'
                                      };



  //Creating the vector.
  vector<char> availableLettersVector;

  //Initialize vector.
  availableLettersVector.reserve(ARRAY_SIZE);
  for (int i = 0; i < (ARRAY_SIZE); ++i)
  {
    // NOTE 2014.03.04 ALLWAYS use push_back() to add an element.
    availableLettersVector.push_back(availableLetters[i]);
  }



  //Initialize Global variables.
  countLetter = 0;
  lettersAvailableCount = 0;



  // Local variables
  int randomNumber = 0;
  int lowest = 0, highest = 0, range = 0;

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    ++countLetter;
    lettersAvailableCount = (ARRAY_SIZE - countLetter);

    highest = lettersAvailableCount;
    range = (highest - lowest) + 1; // This range decreases while the loop progress.

    outputDebug ? cout << "GETTING THE LETTER (countLetter - range): " << countLetter << " - " << range << endl : false; //DEBUG


    // Testing possible letters
    char possibleLetter = '@'; //Initialized with invalid value.
    while ( possibleLetter == '@'  )
    {
      randomNumber = lowest + rand() % range;
      possibleLetter = availableLettersVector[randomNumber];

      outputDebug ? cout << "Possible letter (char - random number - lettersAvailableCount) " << possibleLetter << " - " << randomNumber << " - " << lettersAvailableCount << endl : false; // DEBUG

      possibleLetter = checkValidPossibleLetter(possibleLetter, outputDebug); // Return '@' if invalid.
    } // WHILE ends


    //--- Output for DEBUG
    if (outputDebug)
    {
      cout << "availableLettersVector: ";
      for (int i = 0; i < availableLettersVector.size(); ++i)
      {
        cout << availableLettersVector[i] << " ";
      }
      cout << endl;
    }
    //---




    // We got the new letter
    randomArrayLetters[ countLetter - 1 ] = possibleLetter;

    // Remember initialize the ITERATOR: vector.begin().
    outputDebug ? cout << " To erase() " << endl : false; //DEBUG
    availableLettersVector.erase(availableLettersVector.begin() + randomNumber); //the letter is no longer available.


    //--- Output for DEBUG
    if (outputDebug)
    {
      cout << endl << "Got the letter: " << possibleLetter  << endl; //DEBUG
      cout << endl;

      cout << "randomArrayLetters: ";
      for (int i = 0; i < countLetter; ++i)
      {
        cout << randomArrayLetters[i] << " ";
      }
      cout << endl;

      cout << "availableLettersVector: ";
      for (int i = 0; i < availableLettersVector.size(); ++i)
      {
        cout << availableLettersVector[i] << " ";
      }
      cout << endl;

      cout << endl;
      cout << endl;
    }
    //---

  }//-- main FOR end.

} //-- function




void getCipherArray(char *finalArray, bool outputDebug)
{
  // Recursion to prevent the letter Z at the end
  generateRandomArray(finalArray, outputDebug);
  while ( finalArray[25] == 'Z' )
  {
    if (outputDebug)
    {
      cout << "WARNING: Letter Z at the same position. Regenerating array." << endl; //DEBUG
      cout << endl;
      cout << endl;
    }
    generateRandomArray(finalArray, outputDebug);
  }

} //-- function



char cipherCharacter (char charInput, char *cipherArray)
{
/*  char cipherArray[26] = {'B', 'A', 'D', 'C', 'F', 'E', 'H', 'G', 'J', 'I', 'L', 'K', 'N'
                          , 'M', 'P', 'O', 'R', 'Q', 'T', 'S', 'V', 'U', 'X', 'W', 'Z', 'Y'
                         };
*/
  int number = charInput;

  // cout << number << "  -  "; //DEBUG
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

  return  cipherArray[ number ];

} //-- function



int main()
{
  cout << "Substitution ciphertext, generating the cipher array." << endl;


  // Generate the dinamic array
  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };
  bool outputDebug = false; //Switch to TURN ON/OFF the output of debug messages.
  srand(time(NULL)); //seed - Keep it out of any loop.
  getCipherArray(substitutionLetters, outputDebug);

  // Output
  cout << endl;
  cout << "The dynamic substitution array." << endl;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << substitutionLetters[i] << " ";
  }
  cout << endl;
  cout << endl;



  // Convert the message
  cout << "Enter the text to convert (valid english letters)." << endl;
  char digitChar = cin.get();
  while (digitChar != 10)   /*Check for the ENTER key.*/
  {
    cout << cipherCharacter(digitChar, substitutionLetters);

    /* DEBUG
        cout << digitChar << " ";

        int number = digitChar;
        cout << number << endl;
    */

    digitChar = cin.get();
  }


  cout << endl;
  return 0;
}
