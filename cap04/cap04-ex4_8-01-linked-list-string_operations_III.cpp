//2014.07.13 Gustaf-37 - CTG.


/* EXERCISE 4-8:

Add a function to the linked-list string implementation called removeChars to
remove a section of characters from a string based on the position and length.

  For example, removeChars(s1, 5, 3) would remove the three characters starting
  at the fifth character in the string.

  Make sure the removed nodes are properly deallocated.



=== PLAN ===

OK - Extends the code:
/cap04-ex4_7-01-linked-list-string_operations_II.cpp

OK - Review reference code:
/cap04-ex4_5-01-linked-list-removeRecord.cpp


OK - Analisis. Two possible ways:
  1. Use an auxiliary function that removes a node and call it again and again.
  The problem is: in a very long list, it has to start from the beginning over and over.

  2. Use the code from the auxiliary function in a loop.


OK - removeChars function.
  OK -- Make sure the removed nodes are properly deallocated.
OK - Tests.


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


void concatenateLists(charCollection &charListResult, charCollection addList)
{
  // -- Go over the second list and append each letter to the first list
  charNode *loopPtr = addList;
  while (loopPtr != NULL)
  {
    appendChar(charListResult, loopPtr -> letter);

    loopPtr = loopPtr -> next;
  }

  // Cleaning
  loopPtr  = NULL;
}


void removeChars(charCollection &charListResult, int startPos, int positions)
{

  charNode *beforeNode = NULL;
  charNode *removeNode = NULL;
  int count = 1;

  // Go over the list and checks the start position.
  // Remove every node but being careful with the NULL node.

  charNode *loopPtr = charListResult;
  while (loopPtr != NULL)
  {
    if (count == startPos)
    {
      for (int i = 1; (i <= positions && loopPtr != NULL); ++i) // TRICK: NULL check.
      {
        removeNode = loopPtr;

        if (beforeNode == NULL)
        {
          charListResult = charListResult -> next; // New head.
        }
        else
        {
          beforeNode -> next = loopPtr -> next; // New link.
        }
        delete[] removeNode; // Cleanning.

        loopPtr = loopPtr -> next; // WARNING: Next node could be NULL.
      }//-FOR
    }//-IF

    count++;
    beforeNode = loopPtr;

    if (loopPtr != NULL) // Prevents error: "Segmentation fault (core dumped)"
      loopPtr = loopPtr -> next;
  }
}




int main()
{
  cout << "Various string operations using linked list." << endl;


  // -- Test I
  cout << endl << "Test APPEND and CHARACTER_AT." << endl;

  charCollection cc = NULL;
  outputCharList(cc);

  appendChar(cc, 'A');
  appendChar(cc, 'B');
  appendChar(cc, 'C');
  outputCharList(cc);

  outputCharacterAt(cc, 1);
  outputCharacterAt(cc, 4);


  // -- Test II
  cout << endl << "Test CONCATENATE." << endl;

  charCollection cc2 = NULL;
  outputCharList(cc2);

  appendChar(cc2, 'x');
  appendChar(cc2, 'y');
  outputCharList(cc2);

  concatenateLists(cc, cc2);
  outputCharList(cc);


  // -- Test III
  cout << endl << "Test REMOVE CHARACTERS." << endl;

  // removeChars(cc, 1, 7); //Removes all
  removeChars(cc, 2, 2);
  outputCharList(cc);


  // Cleaning
  cc  = NULL;
  cc2 = NULL;

  cout << endl;
  return 0;
}
