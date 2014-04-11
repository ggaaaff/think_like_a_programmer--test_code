//2014.03.10 Gustaf - CTG.


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

-
-

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



void identifyLimits (arrayString sourceStr, arrayString targetStr, posList &positionsResult)
{
  // -- Simulate result, for simplicity in this test archive.
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

  // Get the initial positions of the Target in the Source
  posList resultLimits = NULL; // Head pointer of linked list.
  identifyLimits(source, target, resultLimits);


  cout << "Index of Initial Positions: ";
  posIniNode *loopPtr = resultLimits;
  while (loopPtr != NULL)
  {
    cout << loopPtr->posInitial << " - ";
    loopPtr = loopPtr->next;
  }
  cout << endl;



  //


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
  const int REPLACE_SIZE = 3; arrayString r = new char[REPLACE_SIZE];
  r[0] = 'a'; r[1] = 'b'; r[2] = 0;


  // -- Execution
  cout << "Initial string : " << s << endl;
  cout << "Target string  : " << t << endl;

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
