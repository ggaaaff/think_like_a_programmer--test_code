//2014.03.10 - 2014.03.11
//2014.03.13 Gustaf - CTG.


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

- Function to replace the string.
  ok- Test Mode 01: target (one letter) and replace (one letter).
  ok- Test Mode 02: target (one letter) and replace (two letter).
  - Test Mode 03: target (one letter) and replace (three letter).
  - Test Mode 04: target (two letter) and replace (three letter).
  - Test Mode 05: target (three letter) and replace (three letter).

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
  // -- SIMULATE result, for simplicity in this test archive.
  //
  // This function works and its code is in the file:
  // cap04-ex4_3-02-test-identify_targets-function.cpp
  // ---


  // New nodes
  posIniNode *newNode1 = new posIniNode;
  newNode1 -> posInitial = 0;
  newNode1 -> next = NULL;

  posIniNode *newNode2 = new posIniNode;
  newNode2 -> posInitial = 4;
  newNode2 -> next = NULL;

  // Linked list
  newNode1 -> next = newNode2;
  positionsResult = newNode1;

  // Cleaning
  newNode1 = NULL;
  newNode2 = NULL;

  // ---

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

    // TODO: Test this.
    cout << "DEBUG: This message should not appear." << endl;
  }

  // --
  int sLength = lengthFunction(source);
  int tLength = lengthFunction(target);
  int rLength = lengthFunction(replace);


  // -- TEST MODES
  int TEST_MODE = 0;

  if ( tLength == 1 && rLength == 1 )
  {
    TEST_MODE = 1;
  }

  if ( tLength == 1 && rLength == 2 )
  {
    TEST_MODE = 2;
  }


  // Test Mode 01: target (one letter) and replace (one letter).
  if (TEST_MODE == 1)
  {
    posIniNode *loopPtr_ONE = getResultLimits;
    while (loopPtr_ONE != NULL)
    {
      cout << "DEBUG: (Initial position) " << loopPtr_ONE -> posInitial << endl;

      source[ loopPtr_ONE -> posInitial ] = replace[0];
      loopPtr_ONE = loopPtr_ONE -> next;
    }
    cout << endl;
  }


  // Test Mode 02: target (one letter) and replace (two letter).
  if (TEST_MODE == 2)
  {

    // New size for the result string: size of original string,
    //    minus the letters for all the targets,
    //    plus the new letters, plus the NULL at the end of the string.
    int newSizeSource = sLength - (countPos * tLength) + (countPos * rLength) + 1;
    arrayString newS = new char[newSizeSource];
    cout << "DEBUG: (Source length - New Source size): " << sLength << " - " << newSizeSource << endl;

    posIniNode *loopPtr_TWO = getResultLimits;
    int j = 0;

    for (int i = 0; i < sLength; ++i)
    {

      if ( (loopPtr_TWO != NULL) && (i == loopPtr_TWO -> posInitial) )
      {
        cout << "DEBUG: (Initial position) " << loopPtr_TWO -> posInitial << endl;

        newS[j] = replace[0];
        cout << "DEBUG: replace 0 "  << endl;
        j++;
        newS[j] = replace[1];
        cout << "DEBUG: replace 1 "  << endl;
        j++;

        loopPtr_TWO = loopPtr_TWO -> next;
      }
      else
      {
        newS[j] = source[i];
        j++;
      }

    }
    newS[newSizeSource - 1] = 0; // NULL at the end.
    cout << "DEBUG: NULL "  << endl;


    // -- Free the old value and return the new value.
    delete[] source;
    source = newS;
  }



  // Test Mode 03: target (one letter) and replace (three letter).
  // Test Mode 04: target (two letter) and replace (three letter).
  // Test Mode 05: target (three letter) and replace (three letter).

}


void replaceFunctionTester ()
{

  // -- SOURCE STRING
  const int ARRAY_SIZE = 9;
  arrayString s = new char[ARRAY_SIZE];

  s[0] = 'a'; s[1] = 'b'; s[2] = 'c'; s[3] = 'd';
  s[4] = 'a'; s[5] = 'b'; s[6] = 'c'; s[7] = 'e'; s[8] = 0;


  // -- Different tests for the TARGET STRING

  // const int TARGET_SIZE = 9;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'd';
  // t[4] = 'a'; t[5] = 'b'; t[6] = 'c'; t[7] = 'e'; t[8] = 'f'; t[9] = 0;

  // const int TARGET_SIZE = 8;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'd';
  // t[4] = 'a'; t[5] = 'b'; t[6] = 'c'; t[7] = 'a'; t[8] = 0;

  // const int TARGET_SIZE = 4;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 0;

  // const int TARGET_SIZE = 3;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'b'; t[1] = 'c'; t[2] = 0;

  const int TARGET_SIZE = 2; arrayString t = new char[TARGET_SIZE];
  t[0] = 'a'; t[1] = 0;

  /// ---



  // -- REPLACE STRING
  // const int REPLACE_SIZE = 4; arrayString r = new char[REPLACE_SIZE];
  // r[0] = 'x'; r[1] = 'y'; r[2] = 'z'; r[3] = 0;

  const int REPLACE_SIZE = 3; arrayString r = new char[REPLACE_SIZE];
  r[0] = 'x'; r[1] = 'y'; r[2] = 0;

  // const int REPLACE_SIZE = 2; arrayString r = new char[REPLACE_SIZE];
  // r[0] = 'x'; r[1] = 0;


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
