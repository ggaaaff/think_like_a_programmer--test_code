//2014.03.12 Gustaf - CTG.


/*
A crystal clear example:
http://www.vias.org/tmdatanaleng/cc_quartile.html


The calculation of the quartiles is sometimes not quite clear (especially if the number of observations of a sample
is not divisible by four). We therefore provide exact instructions how to calculate the quartiles.
Assuming a sample of N observations the quartiles are defined as follows
("round" stands for the rounding to the nearest integer) :

  1. quartile : the value of the sorted series of observations having the position x = round(0.25 * (N + 1))
  2. quartile (median) : if N is even, Q2 is the mean of the two values at the positions N / 2 and N / 2 + 1;
     if N is odd, Q2 is the value at the position (N + 1) / 2
  3. quartile: the value of the sorted series having the position x = round(0.75 * (N + 1))

  Example:  Assume that we have obtained the following 20 observations:
  2, 4, 7, -20, 22, -1, 0, -1, 7, 15, 8, 4, -4, 11, 11, 12, 3, 12, 18, 1

  In order to calculate the quartiles we first have to sort the observations:
  -20, -4, -1, -1, 0, 1, 2, 3, 4, 4, 7, 7, 8, 11, 11, 12, 12, 15, 18, 22

  The position of the first quartile is x = round(0.25 * (20 + 1)) = round(5.25) = 5,
  which means that Q1 is the 5th value of the sorted series, namely Q1 = 0.
  The other quartiles are calculated in the same way resulting in Q2 = 5.5 and Q3 = 12.

  Remark on practical aspects: quartiles are usually calculated only for samples with more than 12 observations
  (a minimum of 20 observations would be even better).


*/



#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;


int compareFunc (const void *a, const void *b)
{
  // qsort Function.
  return ( *(int *)a - * (int *)b );
} //-- function



void getQuartiles(double *quartilesReturnArray, int observationsArray[], int N )
{
  // Order the input array (observationsArray), 
  // calculate and return the quartiles in an array (quartilesReturnArray).

  qsort(observationsArray, N, sizeof(int), compareFunc);

  cout << "Sorted grades:  ";
  for (int i = 0; i < N; ++i)
  {
    cout << observationsArray[i] << " ";
  }
  cout << endl << endl;


  // Calculate the Quartiles
  int indexQ1 = 0, indexQ2 = 0, indexQ3 = 0;
  int Q1 = 0, Q3 = 0;
  double Q2 = 0.0;

  indexQ1 = (round(0.25 * (N + 1))) - 1;
  Q1 = observationsArray[indexQ1];

  if ((N % 2) == 0)
  {
    cout << " EVEN" << endl;
    indexQ2 = (N / 2) - 1;
    Q2 = ( ( observationsArray[indexQ2] + observationsArray[indexQ2 + 1] ) / 2.0);
  }
  else
  {
    indexQ2 = ((N + 1) / 2) - 1;
    Q2 = observationsArray[indexQ2];
    cout << " ODD" << endl;
  }

  indexQ3 = (round(0.75 * (N + 1))) - 1;
  Q3 = observationsArray[indexQ3];


  cout << "Quartiles indexes (Q1 Q2 Q3): " << indexQ1 << " - " << indexQ2 << " - " << indexQ3 << endl; // DEBUG
  cout << "Quartiles (Q1 Q2 Q3): " << Q1 << " - " << Q2 << " - " << Q3 << endl; // DEBUG

  quartilesReturnArray[0] = Q1;
  quartilesReturnArray[1] = Q2;
  quartilesReturnArray[2] = Q3;

} //-- function




int main()
{
  cout << "Quartiles function." << endl;

  const int ARRAY_SIZE = 20;
  int aux_gradesArray[ARRAY_SIZE] = {2, 4, 7, -20, 22, -1, 0, -1, 7, 15, 8, 4, -4, 11, 11, 12, 3, 12, 18, 1};

  // const int ARRAY_SIZE = 23;
  // int aux_gradesArray[ARRAY_SIZE] = {2, 4, 7, -20, 22, -1, 0, -1, 7, 15, 8, 4, -4, 11, 11, 12, 3, 12, 18, 1, 7, 9, 3};


  const int QUARTILES_SIZE = 3;
  double quartilesArray[QUARTILES_SIZE] = {0.0, 0.0, 0.0};

  getQuartiles(quartilesArray, aux_gradesArray, ARRAY_SIZE); // Order the array and get the quartiles.

  cout << "Quartiles (Q1 Q2 Q3): " << quartilesArray[0] << " - " << quartilesArray[1] << " - " << quartilesArray[2] << endl;

  cout << endl;
  return 0;
}
