//2014.03.24 - 2014.03.26 Gustaf - CTG.


/* EXERCISE 4-1:
Design your own: Take a problem that you already know how to solve using
an array but that is limited by the size of the array. Rewrite the code to remove
that limitation using a dynamically allocated array.


-- Calculate the MEDIAN
Loosely based in: cap03-ex3_2-01-statistic-median.cpp

  The median of a set of values is the “one in the middle,”
  such that half of the other values are higher and half of the other values are lower.

  If there is an even number of values, the median is the simple average of the two values in the middle.

  For example, in the set 10, 6, 2, 14, 7, 9, the values in the middle are 7 and 9.
  The average of 7 and 9 is 8, so 8 is the median.



=== PLAN ===

OK - Create a dinamic array of integers.
OK - Output the array.

OK - Algorithm to calculate the median.
  ok - qsort.


#include <cmath>


*/



#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;


typedef int *arrayInt;

const int AEOA = -99; // Artificial END of the dinamic array.


int length(arrayInt a)
{
  // Determine the length of the array.
  int count = 0;
  while (a[count] != AEOA) 
  {
    count++;
  }
  return count;
}


void outputArray(arrayInt a)
{
  int index = 0;
  while (a[index] != AEOA )
  {
    cout << a[index] << " ";
    index++;
  }
  cout << endl;
}



int compareFunc (const void *a, const void *b)
{
  return ( *(int *)a - *(int *)b );
}



double functionMedian (arrayInt a, int ARRAY_SIZE)
{

  //NOTE: using the non integer 2.0 to produce a result of type "double".
  int middle = trunc(ARRAY_SIZE / 2.0);
  if (ARRAY_SIZE % 2 == 0)
  {
    //average of the two values in the middle.
    return ( (a[ middle - 1 ] + a[ middle ]) / 2.0 ); //NOTE: it is a zero based array.
  }
  else
  {
    //the value in the middle.
    return a[ middle ]; //NOTE: it is a zero based array.
  }

}



int main()
{
  cout << "Dinamic array - Statistic Median (of positive integers)." << endl;


  arrayInt integerSerie = new int[7];
  integerSerie[0] = 10;
  integerSerie[1] = 6;
  integerSerie[2] = 2;
  integerSerie[3] = 14;
  integerSerie[4] = 7;
  integerSerie[5] = 9;
  integerSerie[6] = AEOA; // Artificial END of the dinamic array.


  int ARRAY_SIZE = length(integerSerie);

  cout << "Sorted array: "; 
  qsort(integerSerie, ARRAY_SIZE, sizeof(int), compareFunc);
  outputArray(integerSerie);

  cout << "MEDIAN: " << functionMedian(integerSerie, ARRAY_SIZE) << endl;


  cout << endl;
  return 0;
}
