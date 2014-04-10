//2014.04.01 - 2014.04.02 - 2014.04.03 - 2014.04.05
//2014.04.07 - 2014.04.08 - 2014.04.09 Gustaf - CTG.


/* OBJECTIVE :



=== PLAN ===

OK - Function to identify the start position of the target inside the source string.

   ok- Convert to a function and Test functionality.

   ok- Return a list with the positions.
   For each target string found in the source string, just the initial position is needed.
   The final can be calculated easily with the length of the target string.

*/



#include <iostream>

using namespace std;



typedef char *arrayString;
typedef int  *arrayInt;



struct posIniNode
{
  int posInitial;

  posIniNode *next; // Pointer to the same struct.
};

typedef posIniNode *posList; // type reserved for the head pointer.


void pushPosition(posList &posResult, int posIni)
{
  // After the new node is created, it is linked into the list at the BEGINNING.

  // New node
  posIniNode *newNode = new posIniNode;
  newNode -> posInitial = posIni;
  newNode -> next = NULL;

  // linked at the BEGINNING of the list.
  newNode -> next = posResult;
  posResult = newNode; // new head pointer.

  // Cleaning
  // DOUBT 2014.04.09 Is it enough?
  newNode  = NULL;
}


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
        // pushPosition(newPositionsResult, posIni); // A new node for every new initial position.
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

            // pushPosition(newPositionsResult, posIni); // A new node for every new initial position.
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



void identifyLimitsTester ()
{

  const int ARRAY_SIZE = 9;
  arrayString a = new char[ARRAY_SIZE];

  a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd';
  a[4] = 'a'; a[5] = 'b'; a[6] = 'c'; a[7] = 'a'; a[8] = 0;


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


  // -- Linked list
  posList resultLimits = NULL; // Head pointer.


  cout << "Initial string : " << a << endl;
  cout << "Target string  : " << t << endl;
  cout << endl;
  identifyLimits(a, t, resultLimits);


  cout << "Index of Initial Positions: ";
  posIniNode *loopPtr = resultLimits;
  while (loopPtr != NULL)
  {
    cout << loopPtr->posInitial << " - ";
    loopPtr = loopPtr->next;
  }
  cout << endl;


  // Free dynamic memory.
  delete[] a;
  delete[] t;
  delete[] resultLimits;

}



int main()
{
  cout << "Variable-Length String Manipulation. Function to identify limits." << endl;
  identifyLimitsTester();


  cout << endl;
  return 0;
}
