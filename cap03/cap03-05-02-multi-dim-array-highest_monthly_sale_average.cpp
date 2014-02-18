//2014.02.16 Gustaf - CTG.


/*
Suppose we wanted to display the highest agent monthly sales average.

NOTE: This technique of considering a multidimensional array as an array of
arrays follows directly from our core principle of breaking problems up into
simpler components and in general makes multidimensional array problems
a lot easier to conceptualize.

*/


#include <iostream>
#include <string>

using namespace std;


double arrayAverage(int intArray[], int ARRAY_SIZE)
{
  double sum = 0;
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    sum += intArray[i];
  }
  double average = sum / ARRAY_SIZE;
  return average;
}


int main()
{
  cout << "Finding highest agent monthly sales average. \n";


  const int NUM_AGENTS = 3;
  const int NUM_MONTHS = 12;
  int sales[NUM_AGENTS][NUM_MONTHS] =
  {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
  };


  double highestAverage = arrayAverage(sales[0], 12);
  for (int agent = 1; agent < NUM_AGENTS; agent++)
  {
    double agentAverage = arrayAverage(sales[agent], 12);
    if (agentAverage > highestAverage)
      highestAverage = agentAverage;
  }


  cout << highestAverage << " highest agent monthly sales average. \n";

  cout << "\n";
  return 0;
}
