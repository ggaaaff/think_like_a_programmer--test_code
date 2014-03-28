//2014.03.28 Gustaf - CTG.


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
- Traverse (go over) the SOURCE string and identify the initial and final positions in the TARGET string.
  ok- Identify one character.
  ok- Identify two characters.
  - Identify lot of characters.

*/



#include <iostream>

using namespace std;


typedef char *arrayString;



int main()
{
  cout << "Variable-Length String Manipulation. REPLACE" << endl;



  int ARRAY_SIZE = 9;
  int posIni = -1, posFinal = -1;


  arrayString a = new char[ARRAY_SIZE];
  a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd';
  a[4] = 'a'; a[5] = 'b'; a[6] = 'e'; a[7] = 'e'; a[8] = 0;
  cout << a << endl;

  // --- Identifying one character.
  char targetChar = 0;
  targetChar = 'b';
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {

    if (a[i] == targetChar)
    {
      posIni = i;
      cout << "Target - index: " << targetChar << " - " << posIni << endl;
    }

  }
  cout << endl;
  cout << endl;



  // --- Identifying two characters.
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

    // Find next char, in next cicle.
    if ( (posIni != -1) && (i == (posIni +1) ) && (a[i] == targetArray[1]) )
    {
      posFinal = i;
  
      cout << "Target - index: " << targetArray[0] << " - " << posIni << endl;
      cout << "Target - index: " << targetArray[1] << " - " << posFinal << endl;

      posIni = -1, posFinal = -1; // Reset.
    }

  }




  delete a;


  cout << endl;
  return 0;
}
