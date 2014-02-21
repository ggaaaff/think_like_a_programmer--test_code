//2014.02.20 Gustaf - CTG.


/* EXERCISE 3-3:
Write a bool function that is passed an array and the number of elements in
that array and determines whether the data in the array is sorted.

This should require only one pass!


=== PLAN ===

OK - Make the funtion.
  OK - Check if there is a change in the order.
NOP - Optional show the sorted array.

*/


#include <iostream>
#include <cstdlib>


using namespace std;


bool checkSortArray (int arrayAux[], int ARRAY_SIZE)
{
  int countChange = 0;
  int leftNumber = arrayAux[0];
  for (int i = 1; i < ARRAY_SIZE; i++)
  {
    if ( leftNumber > arrayAux[i]) //Check the order.
    {
      countChange++;

      // leftNumber = arrayAux[i]; //DEBUG
      // cout << "Inside if" << endl;
      break;
    }
  }

  if (countChange == 0)
  {
    return true; //Array is sorted.
  }
  else
  {
    return false; //Array is not sorted.
  }

}



int main()
{
  cout << "Check if an array is sorted." << endl;

  const int ARRAY_SIZE = 7;
  int arrayIntegers_1[ARRAY_SIZE] = {5, 3, 6, 7, 2, 9, 1};
  int arrayIntegers_2[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7};

  bool isSorted = false;
  isSorted = checkSortArray(arrayIntegers_1, ARRAY_SIZE);
  cout << "The array I is ";  
  if (isSorted) cout << ""; else cout << "not "; 
  cout << "sorted." << endl; 

  isSorted = checkSortArray(arrayIntegers_2, ARRAY_SIZE);
  cout << "The array II is ";  
  if (isSorted) cout << ""; else cout << "not "; 
  cout << "sorted." << endl; 


  cout << endl;
  return 0;
}
