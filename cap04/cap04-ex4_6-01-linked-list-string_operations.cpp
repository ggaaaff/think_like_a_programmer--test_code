//2014.07.11 Gustaf-37 - CTG.


/* EXERCISE 4-6:

Let’s create an implementation for strings that uses a linked list of characters
INSTEAD OF dynamically allocated arrays.

  So we’ll have a linked list where the data payload is a single char;
  this will allow strings to grow without having to recreate the entire string.

We’ll start by implementing the append and characterAt functions.


=== PLAN ===

OK - Review reference code:
/cap04-04-01-variable_length_string.cpp             //Arrays
/cap04-ex4_4-01-string-manipulation-oneBased.cpp    //Arrays
/cap04-ex4_3-02-test-identify_targets-function.cpp  //Linked list
/cap04-ex4_5-01-linked-list-removeRecord.cpp        //Linked list


OK - output function.
OK - append function.
OK - characterAt function.
OK - Varios tests.


*/



#include <iostream>
#include <string>

using namespace std;


struct charNode
{
  char letter;

  // To make a linked list, we need a pointer to the same struct.
  charNode *next;
};

typedef charNode *charCollection;
// For readability we are using the charCollection type
// only for variables that will refer to the whole linked list.


void outputCharList(charCollection cc)
{
  cout << "String: ";
  charNode *loopPtr = cc;
  while (loopPtr != NULL)
  {
    cout << loopPtr -> letter;
    loopPtr = loopPtr -> next;
  }
  cout << endl;
}


void appendChar(charCollection &charListResult, char charAppend)
{
  // After the new node is created, it is linked into the list at the END.

  // -- New node
  charNode *newNode = new charNode;
  newNode -> letter = charAppend;
  newNode -> next   = NULL;

  // -- Go to the last node
  charNode *lastNode = NULL;

  charNode *loopPtr = charListResult;
  while (loopPtr != NULL)
  {
    lastNode = loopPtr; // Current node verified.
    loopPtr = loopPtr -> next; // Next node to verify if have data.
  }

  // -- New node linked at the end
  if (lastNode == NULL)
  {
    // Linked list is empty, this is the first node.
    charListResult = newNode;
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


void outputCharacterAt(charCollection cc, int position)
{
  int count = 1;
  char auxLetter = 0;

  // -- Go over the list
  charNode *loopPtr = cc;
  while (loopPtr != NULL)
  {
    if (count == position)
    {
      auxLetter = loopPtr -> letter;
    }

    loopPtr = loopPtr -> next;
    count++;
  }

  // -- Output 
  if (auxLetter != 0)
  {
    cout << "Character at position " << position << ": " << auxLetter << endl;
  }
  else
  {
    cout << "Character at position " << position << ": NOT found." << endl;
  }
}



int main()
{
  cout << "Various string operations using linked list." << endl;


  // -- Test
  charCollection cc = NULL;
  outputCharList(cc);

  appendChar(cc, 'A');
  appendChar(cc, 'B');
  outputCharList(cc);

  outputCharacterAt(cc, 1);
  outputCharacterAt(cc, 4);


  // Cleaning
  cc = NULL;

  cout << endl;
  return 0;
}
