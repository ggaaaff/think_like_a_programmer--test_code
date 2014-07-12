//2014.07.12 Gustaf-37 - CTG.


/* EXERCISE 4-7:

Following up on the previous exercise, implement the concatenate function.

  Note that if we make a call concatenate(s1, s2), where both parameters are
  pointers to the first nodes of their respective linked lists, the function should
  create a copy of each of the nodes in s2 and append them to the end of s1.

    That is, the function should not simply point the next field of the last node in
    s1’s list to the first node of s2’s list.



=== PLAN ===

OK - Extends the code:
/cap04-ex4_6-01-linked-list-string_operations.cpp


 - Concatenate function.
 - Tests.
 

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



int main()
{
  cout << "Various string operations using linked list." << endl;


  // -- Test
  cout << endl << "Test APPEND and CHARACTER_AT." << endl;

  charCollection cc = NULL;
  outputCharList(cc);

  appendChar(cc, 'A');
  appendChar(cc, 'B');
  appendChar(cc, 'C');
  outputCharList(cc);

  outputCharacterAt(cc, 1);
  outputCharacterAt(cc, 4);


  // -- Test
  cout << endl << "Test CONCATENATE." << endl;

  charCollection cc2 = NULL;
  outputCharList(cc2);

  appendChar(cc2, 'x');
  appendChar(cc2, 'y');
  outputCharList(cc2);

  concatenateLists(cc, cc2);
  outputCharList(cc);


  // Cleaning
  cc  = NULL;
  cc2 = NULL;

  cout << endl;
  return 0;
}
