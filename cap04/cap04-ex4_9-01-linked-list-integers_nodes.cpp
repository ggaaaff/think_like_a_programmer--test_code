//2014.07.13 Gustaf-37 - CTG.


/* EXERCISE 4-9 :

Imagine a linked list where instead of the node storing a character, the node
stores a digit: an int in the range 0–9. 

  We could represent positive numbers of any size using such a linked list; 
  the number 149, for example, would be a linked list in which the first node 
  stores a 1, the second a 4, and the third and last a 9. 

Write a function intToList that takes an integer value and produces a
linked list of this sort. 

  Hint: You may find it easier to build the linked list backward, 
  so if the value were 149, you would create the 9 node first.



=== PLAN ===

OK - append function.
OK - output function.
OK - intToList function.
OK - Tests.

*/



#include <iostream>
#include <string>

using namespace std;



struct digitNode
{
  int digit;

  // To make a linked list, we need a pointer to the same struct.
  digitNode *next;
};

typedef digitNode *digitCollection;
// For readability we are using the digitCollection type
// only for variables that will refer to the whole linked list.


void outputDigitList(digitCollection dc)
{
  cout << "Number: ";
  digitNode *loopPtr = dc;
  while (loopPtr != NULL)
  {
    cout << loopPtr -> digit;
    loopPtr = loopPtr -> next;
  }
  cout << endl;
}


void appendDigit(digitCollection &digitListResult, int digitAppend)
{
  // After the new node is created, it is linked into the list at the END.

  // -- New node
  digitNode *newNode = new digitNode;
  newNode -> digit = digitAppend;
  newNode -> next   = NULL;

  // -- Go to the last node
  digitNode *lastNode = NULL;

  digitNode *loopPtr = digitListResult;
  while (loopPtr != NULL)
  {
    lastNode = loopPtr; // Current node verified.
    loopPtr = loopPtr -> next; // Next node to verify if have data.
  }

  // -- New node linked at the end
  if (lastNode == NULL)
  {
    // Linked list is empty, this is the first node.
    digitListResult = newNode;
  }
  else
  {
    lastNode -> next = newNode;
  }

  // Cleaning
  newNode  = NULL;
  lastNode = NULL;
  loopPtr  = NULL;
}


void intToList(digitCollection &intListResult, int intArray[], int arrSize)
{
  for (int i = 0; i < arrSize; ++i)
  {
    appendDigit(intListResult, intArray[i]);
  }
}



int main()
{
  cout << "A number stored in a linked list." << endl;

  // -- Test I
  cout << endl << "Test APPEND." << endl;

  const int ARRAY_SIZE = 5; int numArray[ARRAY_SIZE] = {0, 1, 2, 3, 6};
  digitCollection dc = NULL;

  intToList(dc, numArray, ARRAY_SIZE);
  outputDigitList(dc);


  // Cleaning
  dc  = NULL;

  cout << endl;
  return 0;
}
