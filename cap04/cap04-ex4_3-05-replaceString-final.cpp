//2014.03.15 Gustaf - CTG.


/* OBJECTIVE :

For our dynamically allocated strings, create a function replaceString that takes
three parameters, each of type arrayString: source, target, and replaceText.

The function replaces every occurrence of target in source with replaceText.

For example,
  if source points to an array containing "abcdabee",
  target points to "ab",
  and replaceText points to "xyz",
  then when the function ends, source should point to an array containing "xyzcdxyzee".



=== PLAN ===

OK - Function to replace the string.
  ok- Integrate the function that identify the initial positions.
  ok- Test different cases.


*/



#include <iostream>

using namespace std;



typedef char *arrayString;



struct posIniNode
{
  int posInitial;

  posIniNode *next; // Pointer to the same struct.
};

typedef posIniNode *posList; // type reserved for the head pointer.




void appendPosition(posList &posResult, int posIni)
{
  // After the new node is created, it is linked into the list at the END.

  // -- New node
  posIniNode *newNode = new posIniNode;
  newNode -> posInitial = posIni;
  newNode -> next = NULL;

  // -- Go to the last node
  posIniNode *loopNode = NULL;

  posIniNode *loopPtr = posResult;
  while (loopPtr != NULL)
  {
    cout << "DEBUG: LOOP while" << endl;

    loopNode = loopPtr; // Current node verified.
    loopPtr  = loopPtr -> next; // Next node to verify if have data.
  }

  // -- New node linked at the end of the linked list
  if (loopNode == NULL) 
  {
    cout << "DEBUG: NULL" << endl;
    posResult = newNode; 
  }
  else
  {
    cout << "DEBUG: NO NULL" << endl;
    loopNode -> next = newNode;
  }

  // Cleaning
  // DOUBT 2014.04.08 Is it enough?
  newNode  = NULL;
  loopNode = NULL;
  loopPtr  = NULL;
}


int lengthFunction(arrayString s)
{
  // Determine the length of a string array.
  int count = 0;
  while (s[count] != 0) // not includes the "null terminator".
  {
    count++;
  }
  return count;
}



void identifyLimits (arrayString sourceStr, arrayString targetStr, posList &positionsResult)
{

  int posIni = -1, posFinal = -1;

  int SOURCE_SIZE = lengthFunction(sourceStr);
  int TARGET_SIZE = lengthFunction(targetStr);


  // --- Linked list
  posList newPositionsResult = NULL; // Head pointer - Auxiliary.



  // -----------------------------------
  // -----------------------------------

  posIni = -1, posFinal = -1;
  for (int i = 0; i < SOURCE_SIZE; ++i)
  {

    // Find first character.
    if ( (posIni == -1) && (posFinal == -1) && (sourceStr[i] == targetStr[0]) )
    {
      posIni = i;


      // Handles special case of one character.
      if (TARGET_SIZE == 1)
      {
        appendPosition(newPositionsResult, posIni); // A new node for every new initial position.


        cout << "DEBUG: Target initial/final - index: " << targetStr[0] << " - " << posIni << endl; // DEBUG.
        cout << endl;

        posIni = -1, posFinal = -1; // Reset.
      }


      // Handles the cases from two characters until ...
      for (int j = 1; j < TARGET_SIZE; ++j)
      {

        // Check second adjacent character.
        if ( (posFinal == -1) && ( (i + j) == (posIni + j)) )
        {
          if (sourceStr[i + j] == targetStr[j])
          {
            posFinal = i + j;
          }

          if (sourceStr[i + j] != targetStr[j])
          {
            posIni = -1, posFinal = -1; // Reset.
          }
        }


        // Check next adjacent character. BUT not the last.
        if ( (posFinal != -1) && ((i + j) == (posIni + j)) && (j <= (TARGET_SIZE - 2)) )
        {
          if (sourceStr[i + j] == targetStr[j])
          {
            posFinal = i + j;
          }

          if (sourceStr[i + j] != targetStr[j])
          {
            posIni = -1, posFinal = -1; // Reset.
          }
        }


        // Check last adjacent character.
        if ( (posFinal != -1) && ((i + j) == (posIni + j)) && (j == (TARGET_SIZE - 1)) )
        {
          if (sourceStr[i + j] == targetStr[j])
          {
            posFinal = i + j;

            appendPosition(newPositionsResult, posIni); // A new node for every new initial position.


            cout << "DEBUG: Target initial - index: " << targetStr[0] << " - " << posIni << endl;
            cout << "DEBUG: Target final   - index: " << targetStr[j] << " - " << posFinal << endl;
            cout << endl;
          }

          posIni = -1, posFinal = -1; // Reset.
        }

      } // for - inner
    } // if - check the first character.

  } // for - outer


  // -----------------------------------
  // -----------------------------------


  // -- To prevent memory leak.
  delete[] positionsResult;
  positionsResult = newPositionsResult;

}



void replaceFunction(arrayString &source, arrayString target, arrayString replace)
{

  // -- Get the initial positions of the Target in the Source
  posList getResultLimits = NULL; // Head pointer of linked list.
  identifyLimits(source, target, getResultLimits);


  // Count
  int countPos = 0;
  posIniNode *countPtr = getResultLimits;
  while (countPtr != NULL)
  {
    countPos++; // Number of target string found.
    countPtr = countPtr -> next;
  }

  if (countPos == 0)
  {
    cout << "DEBUG: Coincidence not found." << endl;
    return;
  }

  // --
  int sLength = lengthFunction(source);
  int tLength = lengthFunction(target);
  int rLength = lengthFunction(replace);


  // New size for the result string: size of original string,
  //    minus the letters for all the targets,
  //    plus the new letters, plus the NULL at the end of the string.
  int newSourceSize = sLength - (countPos * tLength) + (countPos * rLength) + 1;
  arrayString newS = new char[newSourceSize];
  cout << "DEBUG: (Source length - New Source size): " << sLength << " - " << newSourceSize << endl;


  // Populates the new string.
  // Go over the source string and check if the actual position correspond
  //   to the index (loopPtr_TWO -> posInitial). Then replace all the characters.
  // If the indexes do not match then assign the character from the source to the new string.

  int i = 0; // Index to go over the source string.
  int j = 0; // Index to populate the new string.
  int r = 0; // Index to go over the replace string.
  posIniNode *loopPtr_FOUR = getResultLimits;

  while ( source[i] != 0)
  {
    if ( (loopPtr_FOUR != NULL) && (i == loopPtr_FOUR -> posInitial) )
    {
      cout << "DEBUG: (Initial position) " << loopPtr_FOUR -> posInitial << endl;

      r = 0;
      while (r < rLength)
      {
        cout << "DEBUG: replace " << r << endl;
        newS[j] = replace[r];
        j++;
        r++;
      }

      loopPtr_FOUR = loopPtr_FOUR -> next;
      i = i + tLength; // Jump to the letter after this target.
    }
    else
    {
      newS[j] = source[i];
      i++;
      j++;
    }
  }
  newS[newSourceSize - 1] = 0; // NULL at the end.
  cout << "DEBUG: NULL "  << endl;


  // -- Free the old value and return the new value.
  delete[] source;
  source = newS;

}


void replaceFunctionTester ()
{

  // -- SOURCE STRING

  const int ARRAY_SIZE = 9;
  arrayString s = new char[ARRAY_SIZE];
  s[0] = 'a'; s[1] = 'b'; s[2] = 'c'; s[3] = 'd';
  s[4] = 'a'; s[5] = 'b'; s[6] = 'c'; s[7] = 'e'; s[8] = 0;

  // const int ARRAY_SIZE = 1;
  // arrayString s = new char[ARRAY_SIZE];
  // s[0] = 0;



  // -- TARGET STRING

  // const int TARGET_SIZE = 10;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'd';
  // t[4] = 'a'; t[5] = 'b'; t[6] = 'c'; t[7] = 'e'; t[8] = 'f'; t[9] = 0;

  // const int TARGET_SIZE = 9;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'd';
  // t[4] = 'a'; t[5] = 'b'; t[6] = 'c'; t[7] = 'a'; t[8] = 0;

  // const int TARGET_SIZE = 5;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'e'; t[4] = 0;

  // const int TARGET_SIZE = 4;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 0;

  // const int TARGET_SIZE = 3;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 0;

  const int TARGET_SIZE = 2; arrayString t = new char[TARGET_SIZE];
  t[0] = 'a'; t[1] = 0;

  // const int TARGET_SIZE = 1; arrayString t = new char[TARGET_SIZE];
  // t[0] = 0;



  // -- REPLACE STRING
  
  // const int REPLACE_SIZE = 4; arrayString r = new char[REPLACE_SIZE];
  // r[0] = 'x'; r[1] = 'y'; r[2] = 'z'; r[3] = 0;

  // const int REPLACE_SIZE = 3; arrayString r = new char[REPLACE_SIZE];
  // r[0] = 'x'; r[1] = 'y'; r[2] = 0;

  const int REPLACE_SIZE = 2; arrayString r = new char[REPLACE_SIZE];
  r[0] = 'x'; r[1] = 0;

  // const int REPLACE_SIZE = 1; arrayString r = new char[REPLACE_SIZE];
  // r[0] = 0;


  // -- Execution
  cout << "Initial string : " << s << endl;
  cout << "Target string  : " << t << endl;
  cout << "Replace string : " << r << endl;
  cout << endl;

  replaceFunction(s, t, r);
  cout << "Final string   : " << s << endl;
  cout << endl;


  // Free dynamic memory.
  delete[] s;
  delete[] t;
  delete[] r;

}



int main()
{
  cout << "Variable-Length String Manipulation. Test of REPLACE." << endl;
  replaceFunctionTester();


  cout << endl;
  return 0;
}
