//2014.04.01 - 2014.04.02 - 2014.04.03 - 2014.04.05 - 2014.04.07 Gustaf - CTG.


/* OBJECTIVE :



=== PLAN ===

- Function to identify the start and end positions of the target inside the source string.

   ok- Convert to a function and Test functionality.

   - Return a list with the positions.
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

  // linked at the BEGINNING of the list.
  newNode -> next = posResult; 
  posResult = newNode; // new head pointer.
}


void appendPosition(posList &posResult, int posIni)
{
  // After the new node is created, it is linked into the list at the END

  // New node
  posIniNode *newNode = new posIniNode;
  newNode -> posInitial = posIni;
  newNode -> next = NULL;

  // linked at the end of the list.
  posIniNode *loopPtr = posResult;
  while (loopPtr != NULL)
  {    
    loopPtr = loopPtr->next;
  }

cout << "debug" << endl;
  loopPtr -> next = newNode; // new node linked at the end of the list.
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



// void identifyLimits (arrayString sourceStr, arrayString targetStr, arrayInt &arrayLimitsResult)
void identifyLimits (arrayString sourceStr, arrayString targetStr, posList &positionsResult)
{

  int posIni = -1, posFinal = -1;

  /*
    const int RESULT_SIZE = 2;
    arrayInt newArrayLimits = new int[RESULT_SIZE]; // At the end it is going to point to: arrayLimitsResult.

  */

  int SOURCE_SIZE = lengthFunction(sourceStr);
  int TARGET_SIZE = lengthFunction(targetStr);


  // --- Linked list

  // Head pointer
  posList newPositionsResult;

  /*  // Nodes
    posIniNode *node1 = new posIniNode;
    node1 -> posInitial = -1;

    //Linking the list, just one node.
    newPositionsResult = node1;
    node1 -> next = NULL;

    // Cleaning things up to avoid cross-linking.
    node1 = NULL;
  */
  // ---



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


        cout << "Target initial/final - index: " << targetStr[0] << " - " << posIni << endl;
        cout << endl;

        posIni = -1, posFinal = -1; // Reset.
      }


      // Handles cases from two characters until ...
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


            cout << "Target initial - index: " << targetStr[0] << " - " << posIni << endl;
            cout << "Target final   - index: " << targetStr[j] << " - " << posFinal << endl;
            cout << endl;
          }

          posIni = -1, posFinal = -1; // Reset.
        }

      } // for - inner
    } // if - check the first character.

  } // for - outer


  // -----------------------------------
  // -----------------------------------




  // -- To avoid a memory leak.

  /*
    delete[] arrayLimitsResult;
    arrayLimitsResult = newArrayLimits;
  */

  delete[] positionsResult;
  positionsResult = newPositionsResult;

}



void identifyLimitsTester ()
{

  const int ARRAY_SIZE = 9;
  arrayString a = new char[ARRAY_SIZE];

  a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd';
  a[4] = 'a'; a[5] = 'b'; a[6] = 'c'; a[7] = 'e'; a[8] = 0;


  // -- Different tests for the TARGET STRING

  // const int TARGET_SIZE = 9;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'd';
  // t[4] = 'a'; t[5] = 'b'; t[6] = 'c'; t[7] = 'e'; t[8] = 'f'; t[9] = 0;

  // const int TARGET_SIZE = 8;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 'd';
  // t[4] = 'a'; t[5] = 'b'; t[6] = 'c'; t[7] = 'e'; t[8] = 0;

  // const int TARGET_SIZE = 4;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'a'; t[1] = 'b'; t[2] = 'c'; t[3] = 0;

  // const int TARGET_SIZE = 3;
  // arrayString t = new char[TARGET_SIZE];
  // t[0] = 'b'; t[1] = 'c'; t[2] = 0;

  const int TARGET_SIZE = 2; arrayString t = new char[TARGET_SIZE];
  t[0] = 'a'; t[1] = 0;

  /// ---





  //--------------------------

  // const int RESULT_SIZE = 1;
  // arrayInt resultLimits = new int[RESULT_SIZE];



  // -- Linked list

  // Head pointer
  posList resultLimits;

  /*
    // Nodes
    posIniNode *node1 = new posIniNode;
    node1 -> posInitial = 99;

    //Linking the list, just one node.
    resultLimits = node1;
    node1 -> next = NULL;

    // Cleaning things up to avoid cross-linking.
    node1 = NULL;

  */
  //-------------------------------------------------

  /*
  =================
  struct posIniNode
  {
    int posInitial;

    posIniNode *next; // Pointer to the same struct.
  };

  typedef posIniNode *posList;
  ==========================

  */


  cout << "Initial string : " << a << endl;
  cout << "Target string  : " << t << endl;
  cout << endl;
  identifyLimits(a, t, resultLimits);


  cout << "Initial Positions (reverse order): ";
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
