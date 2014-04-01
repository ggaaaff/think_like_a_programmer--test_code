//2014.03.28 - 2014.03.30 - 2014.03.31 - 2014.04.01 Gustaf - CTG.


/* EXERCISE 4-3 :

For our dynamically allocated strings, create a function replaceString that takes
three parameters, each of type arrayString: source, target, and replaceText.

The function replaces every occurrence of target in source with replaceText.

For example,
  if source points to an array containing "abcdabee",
  target points to "ab",
  and replaceText points to "xyz",
  then when the function ends, source should point to an array containing "xyzcdxyzee".


=== PLAN ===

OK - Diagram of the example.
OK - Traverse (go over) the SOURCE string and identify the initial and final positions of the TARGET string.
  ok- Identify one character.
  ok- Identify two characters.
  ok- Identify three characters.
  ok- Identify four characters.
  ok- Identify FROM one TO lots of characters.

*/



#include <iostream>

using namespace std;


typedef char *arrayString;



int main()
{
  cout << "Variable-Length String Manipulation. TEST identify the limits." << endl;



  int ARRAY_SIZE = 9;
  int posIni = -1, posFinal = -1;


  arrayString a = new char[ARRAY_SIZE];
  a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd';
  a[4] = 'a'; a[5] = 'b'; a[6] = 'e'; a[7] = 'e'; a[8] = 0;

  cout << "Initial string: " << a << endl << endl;



  // --- Identifying one character.
  cout << "Identifying one character." << endl;

  char targetChar = 0;
  targetChar = 'b';
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    if (a[i] == targetChar)
    {
      posIni = i;
      cout << "Target - index: " << targetChar << " - " << posIni << endl;
      cout << endl;
    }

  }


  // --- Identifying two contiguous characters.
  cout << "Identifying two contiguous characters." << endl;

  char targetArray[2] = {'a', 'b'};
  // char targetArray[2] = {'b', 'z'};

  posIni = -1, posFinal = -1;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    // Find first char
    if ( (posIni == -1) && (a[i] == targetArray[0]) )
    {
      posIni = i;
    }

    // Find second adjacent char, in next cicle.
    if ( (posIni != -1) && (i == (posIni + 1) ) && (a[i] == targetArray[1]) )
    {
      posFinal = i;

      cout << "Target - index: " << targetArray[0] << " - " << posIni << endl;
      cout << "Target - index: " << targetArray[1] << " - " << posFinal << endl;
      cout << endl;

      posIni = -1, posFinal = -1; // Reset.
    }

  }


  // --- Identifying three contiguous characters.
  cout << "Identifying three contiguous characters." << endl;

  char targetArrayThree[3] = {'a', 'b', 'c'};
  // char targetArrayThree[3] = {'b', 'e', 'e'};

  posIni = -1, posFinal = -1;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    // Find first char
    if ( (posIni == -1) && (a[i] == targetArrayThree[0]) )
    {
      posIni = i;
    }

    // Check second adjacent character.
    if ( (posIni != -1) && (i == (posIni + 1)) )
    {
      if (a[i] == targetArrayThree[1])
      {
        posFinal = i;
      }

      if (a[i] != targetArrayThree[1])
      {
        posIni = -1, posFinal = -1; // Reset.
      }
    }

    // Check third adjacent character.
    if ( (posIni != -1) && (posFinal != -1) && (i == (posFinal + 1)) )
    {
      if (a[i] == targetArrayThree[2])
      {
        posFinal = i;

        cout << "Target initial - index: " << targetArrayThree[0] << " - " << posIni << endl;
        cout << "Target final   - index: " << targetArrayThree[2] << " - " << posFinal << endl;
        cout << endl;
      }

      posIni = -1, posFinal = -1; // Reset.
    }

  }


  // --- Identifying four contiguous characters.
  cout << "Identifying four contiguous characters." << endl;


  char targetArrayFour[4] = {'a', 'b', 'c', 'd'};
  // char targetArrayFour[4] = {'b', 'c', 'd', 'a'};


  posIni = -1, posFinal = -1;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    // Find first char
    if ( (posIni == -1) && (posFinal == -1) )
    {
      if (a[i] == targetArrayFour[0])
      {
        posIni = i;
      }
    }

    // Check second adjacent character.
    if ( (posIni != -1) && (posFinal == -1) && (i == (posIni + 1)) )
    {
      if (a[i] == targetArrayFour[1])
      {
        posFinal = i;
      }

      if (a[i] != targetArrayFour[1])
      {
        posIni = -1, posFinal = -1; // Reset.
      }
    }

    // Check third adjacent character.
    if ( (posIni != -1) && (posFinal != -1) && (i == (posIni + 2)) )
    {
      if (a[i] == targetArrayFour[2])
      {
        posFinal = i;
      }

      if (a[i] != targetArrayFour[2])
      {
        posIni = -1, posFinal = -1; // Reset.
      }
    }

    // Check fourth adjacent character.
    if ( (posIni != -1) && (posFinal != -1) && (i == (posIni + 3)) )
    {
      if (a[i] == targetArrayFour[3])
      {
        posFinal = i;

        cout << "Target initial - index: " << targetArrayFour[0] << " - " << posIni << endl;
        cout << "Target final   - index: " << targetArrayFour[3] << " - " << posFinal << endl;
        cout << endl;
      }

      posIni = -1, posFinal = -1; // Reset.
    }

  }


  // --- Identifying lots of contiguous characters.
  
  // const int TARGET_SIZE = 9; char targetArrayLots[TARGET_SIZE] = {'b', 'c', 'd', 'a', 'b', 'c', 'e', 'f', 'g'};
  // const int TARGET_SIZE = 7; char targetArrayLots[TARGET_SIZE] = {'b', 'c', 'd', 'a', 'b', 'c', 'e'};
  const int TARGET_SIZE = 3; char targetArrayLots[TARGET_SIZE] = {'a', 'b', 'c'};
  // const int TARGET_SIZE = 2; char targetArrayLots[TARGET_SIZE] = {'a', 'b'};
  // const int TARGET_SIZE = 1; char targetArrayLots[TARGET_SIZE] = {'b'};


  cout << "Identifying " << TARGET_SIZE << " contiguous characters." << endl;


  a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd';
  a[4] = 'a'; a[5] = 'b'; a[6] = 'c'; a[7] = 'e'; a[8] = 0;
  cout << "Initial string: " << a << endl << endl;



  posIni = -1, posFinal = -1;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    // Find first character.
    if ( (posIni == -1) && (posFinal == -1) && (a[i] == targetArrayLots[0]) )
    {
      posIni = i;


      // Handles special case of one character.
      if (TARGET_SIZE == 1)
      {
        cout << "Target initial/final - index: " << targetArrayLots[0] << " - " << posIni << endl;
        cout << endl;

        posIni = -1, posFinal = -1; // Reset.
      }


      // Handles cases from two characters until ...
      for (int j = 1; j < TARGET_SIZE; ++j)
      {

        // Check second adjacent character.
        if ( (posFinal == -1) && ( (i + j) == (posIni + j)) )
        {
          if (a[i + j] == targetArrayLots[j])
          {
            posFinal = i + j;
          }

          if (a[i + j] != targetArrayLots[j])
          {
            posIni = -1, posFinal = -1; // Reset.
          }
        }


        // Check next adjacent character. BUT not the last.
        if ( (posFinal != -1) && ((i + j) == (posIni + j)) && (j <= (TARGET_SIZE - 2)) )
        {
          if (a[i + j] == targetArrayLots[j])
          {
            posFinal = i + j;
          }

          if (a[i + j] != targetArrayLots[j])
          {
            posIni = -1, posFinal = -1; // Reset.
          }
        }


        // Check last adjacent character.
        if ( (posFinal != -1) && ((i + j) == (posIni + j)) && (j == (TARGET_SIZE - 1)) )
        {
          if (a[i + j] == targetArrayLots[j])
          {
            posFinal = i + j;

            cout << "Target initial - index: " << targetArrayLots[0] << " - " << posIni << endl;
            cout << "Target final   - index: " << targetArrayLots[j] << " - " << posFinal << endl;
            cout << endl;
          }

          posIni = -1, posFinal = -1; // Reset.
        }

      } // internal for
    } // if that check the first character.

  } // external for




  delete a; // Free memory of the dynamic array.


  cout << endl;
  return 0;
}
