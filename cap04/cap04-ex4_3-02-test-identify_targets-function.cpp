//2014.04.01 Gustaf - CTG.


/* OBJECTIVE :



=== PLAN ===

- Function to identify the start and end positions of the target inside the source string.
 ok- Convert to a function and Test functionality.
 - Return a dynamic array.

*/



#include <iostream>

using namespace std;



typedef char *arrayString;
typedef int *arrayInt;


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



void identifyLimits (arrayString sourceStr, arrayString targetStr, arrayInt &arrayLimitsResult)
{

  int posIni = -1, posFinal = -1;


  const int RESULT_SIZE = 2;
  arrayInt newArrayLimits = new int[RESULT_SIZE];


  int SOURCE_SIZE = lengthFunction(sourceStr);
  int TARGET_SIZE = lengthFunction(targetStr);


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

            cout << "Target initial - index: " << targetStr[0] << " - " << posIni << endl;
            cout << "Target final   - index: " << targetStr[j] << " - " << posFinal << endl;
            cout << endl;
          }

          posIni = -1, posFinal = -1; // Reset.
        }

      } // internal for
    } // if that check the first character.

  } // external for




  // -----------------------------------
  // -----------------------------------






  // ---
  // To avoid a memory leak, we have to deallocate the array in the heap
  // that our parameter originally pointed to.
  delete[] arrayLimitsResult;

  arrayLimitsResult = newArrayLimits;
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
  // t[0] = 'a'; t[1] = 'b'; t[2] = 0;

  const int TARGET_SIZE = 2; arrayString t = new char[TARGET_SIZE];
  t[0] = 'a'; t[1] = 0;

  /// ---


  const int RESULT_SIZE = 2;
  arrayInt resultLimits = new int[RESULT_SIZE];


  cout << "Initial string : " << a << endl;
  cout << "Target string  : " << t << endl;
  cout << endl;
  identifyLimits(a, t, resultLimits);



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
