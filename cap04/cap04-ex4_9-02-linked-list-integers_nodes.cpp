//2014.07.13 - 2014.07.14 Gustaf-37 - CTG.


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

OK - Reuse code from:
  /cap02-ex2_7-02-test_decimal_to_hexadecimal.cpp
  /cap04-ex4_3-02-test-identify_targets-function.cpp

OK - output function.
OK - push function.
OK - intToList function.
OK - Read the number from the command line.
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


void pushDigit(digitCollection &digitListResult, int intDigit)
{
  // After the new node is created, it is linked into the list at the BEGINNING.

  // New node
  digitNode *newNode = new digitNode;
  newNode -> digit = intDigit;
  newNode -> next  = NULL;

  // linked at the BEGINNING of the list.
  newNode -> next = digitListResult;
  digitListResult = newNode; // new head pointer.

  // Cleaning
  newNode  = NULL;
}


void intToList(digitCollection &intListResult, int numInt)
{
  int numQuotient  = -1;
  int numRemainder = -1;

  // -- Separates the number in its digits and stores them in the linked list
  numQuotient = numInt;
  do
  {
    /*NOTICE: this order is important, Remainder then quotient.*/
    numRemainder = numQuotient % 10;
    numQuotient  = numQuotient / 10;

    // pushDigit(intListResult, 0); //Funny test!
    pushDigit(intListResult, numRemainder);
  }
  while (numQuotient != 0);
}



int main()
{
  cout << "A number stored in a linked list. Digit the number (end with ENTER)." << endl;

  // -- Test
  digitCollection dc = NULL;

  int numInt = 0;
  cin >> numInt;

  intToList(dc, numInt);
  outputDigitList(dc);


  // Cleaning
  dc = NULL;


  cout << endl;
  return 0;
}
