//2014.07.15 Gustaf-37 - CTG.


/* EXERCISE 4-10 :

For the digit list of the previous exercise, write a function that takes two such
lists and produces a new list representing their sum.



=== PLAN ===

OK - Reuse code from:
  /cap04-ex4_9-02-linked-list-integers_nodes.cpp
  /cap02-03-04-test_any_digits.cpp


OK - Sum lists function.
OK - List to integer function.

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


int listToInt(digitCollection aList)
{
  // -- Go over the linked list
  int number = 0;
  digitNode *loopPtr = aList;
  while (loopPtr != NULL)
  {
    number = (number * 10) + loopPtr -> digit;  // The trick.
    loopPtr = loopPtr -> next;
  }

  return number;
}


digitCollection sumLists(digitCollection listA, digitCollection listB)
{
  // -- Transform the lists to integers and do the sum
  int intSum = 0;
  intSum = listToInt(listA) + listToInt(listB);

  // -- Transform the integer and voila!
  digitCollection intListResult = NULL;
  intToList(intListResult, intSum);

  return intListResult;
}



int main()
{
  cout << "Sums two numbers stored in linked lists." << endl;

  // -- Test
  digitCollection a = NULL;
  digitCollection b = NULL;
  digitCollection c = NULL;

  intToList(a, 1200);
  intToList(b, 1000);
  c = sumLists(a, b);
  outputDigitList(c);


  // Cleaning
  a = NULL;
  b = NULL;
  c = NULL;


  cout << endl;
  return 0;
}
