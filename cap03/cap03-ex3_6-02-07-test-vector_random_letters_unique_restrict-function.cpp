//2014.03.05 - 2014.03.06 - 2014.03.07 Gustaf - CTG.



/* OBJECTIVE :

Get a random array of letters.
But they can't be repeated.

  Remember that you can’t substitute a letter for itself. So the first element can’t be A.

Encapsulate in a function.



=== PLAN ===

OK - Function that return the final array.
  OK- Function that check the next random letter.

OK - If the letter Z appear at the end, then generate a new substitution array.

  WARNING: 2014.03.07 There is a problem with the randomness of the array when it is regenerated.
  For no known reason (to me), the program generates the same final array several times until it produces a correct array.

  The test performed was: execute the program several hundred times to generate a log of more than 100MB.
  If we review the log, we could find that the same final array is generated many times.
  BUT if you carefully follow the steps you can see that in the same execution of the program a correct final array is generated, 
  but it is in a next independent call (to the program) that the same array is generated and regenerated.


*/




#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



//Global variables.
const int ARRAY_SIZE = 26;

int countLetter;
int lettersAvailableCount;
//---



char checkValidPossibleLetter ( char possibleLetter )
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


  return possibleLetter;
} //-- function



void generateRandomArray(char *randomArrayLetters)
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

    cout << "GETTING THE LETTER (countLetter - range): " << countLetter << " - " << range << endl; //DEBUG


    // Testing possible letters
    char possibleLetter = '@'; //Initialized with invalid value.
    while ( possibleLetter == '@'  )
    {
      randomNumber = lowest + rand() % range;
      possibleLetter = availableLettersVector[randomNumber];

      cout << "Possible letter (char - random number - lettersAvailableCount) " << possibleLetter << " - " << randomNumber << " - " << lettersAvailableCount << endl; // DEBUG

      possibleLetter = checkValidPossibleLetter(possibleLetter); // Return '@' if invalid.
    } // WHILE ends



    //--- Output for DEBUG
    cout << "availableLettersVector: ";
    for (int i = 0; i < availableLettersVector.size(); ++i)
    {
      cout << availableLettersVector[i] << " ";
    }
    cout << endl;
    //---


    // We got the new letter
    randomArrayLetters[ countLetter - 1 ] = possibleLetter;

    // Remember initialize the ITERATOR: vector.begin().
    cout << " To erase() " << endl; //DEBUG
    availableLettersVector.erase(availableLettersVector.begin() + randomNumber); //the letter is no longer available.



    //--- Output for DEBUG
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
    //---

  }//-- main FOR end.

} //-- function




void getCipherArray(char *finalArray)
{
  // Recursion to prevent the letter Z at the end
  generateRandomArray(finalArray);
  while ( finalArray[25] == 'Z' )
  {
    cout << "WARNING: Letter Z at the same position. Regenerating array." << endl; //DEBUG
    cout << endl;
    cout << endl;
    generateRandomArray(finalArray);
  }

} //-- function



int main()
{
  cout << "Hello world - Linux Mint." << endl;

  char substitutionLetters[ARRAY_SIZE] = {   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                             , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
                                         };
  srand(time(NULL)); //seed - Keep it out of any loop.
  getCipherArray(substitutionLetters);


  cout << endl;
  cout << "The final array." << endl;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << substitutionLetters[i] << " ";
  }
  cout << endl;


  cout << endl;
  return 0;
}
