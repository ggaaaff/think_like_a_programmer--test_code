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

ok- Function to replace the string.
  ok- Test 01: target (one letter) and replace (one letter).
  ok- Test 02: target (one letter) and replace (two letter).
  ok- Test 03: target (one letter) and replace (three letter).
  ok- Test 04: target (two letter) and replace (one letter).
  ok- Test 05: target (two letter) and replace (three letter).
  ok- Test 06: target (three letter) and replace (three letter).

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
  int newSizeSource = sLength - (countPos * tLength) + (countPos * rLength) + 1;
  arrayString newS = new char[newSizeSource];
  cout << "DEBUG: (Source length - New Source size): " << sLength << " - " << newSizeSource << endl;


  int i = 0;
  int j = 0;
  int r = 0;
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
  newS[newSizeSource - 1] = 0; // NULL at the end.
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


  // -- TARGET STRING

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
  // t[0] = 'a'; t[1] = 'b'; t[2] = 0;

  const int TARGET_SIZE = 2; arrayString t = new char[TARGET_SIZE];
  t[0] = 'a'; t[1] = 0;



  // -- REPLACE STRING
  const int REPLACE_SIZE = 4; arrayString r = new char[REPLACE_SIZE];
  r[0] = 'x'; r[1] = 'y'; r[2] = 'z'; r[3] = 0;

  // const int REPLACE_SIZE = 3; arrayString r = new char[REPLACE_SIZE];
  // r[0] = 'x'; r[1] = 'y'; r[2] = 0;

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
