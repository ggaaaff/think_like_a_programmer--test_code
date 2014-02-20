//2014.02.19 Gustaf - CTG.


/* EXERCISE 3-2:
Rewrite the code that finds the agent with the best monthly sales average so
that it finds the agent with the highest median sales.

  As stated earlier, the median of a set of values is the “one in the middle,”
  such that half of the other values are higher and half of the other values are lower.


  If there is an even number of values, the median is the simple average of the two values in the middle.

  For example, in the set 10, 6, 2, 14, 7, 9, the values in the middle are 7 and 9.
  The average of 7 and 9 is 8, so 8 is the median.



=== PLAN ===

OK - Algorithm to calculate the median.
  OK - qsort.
OK - Apply the algorithm for each agent.



== RANT ==
HMMM two hours to get this 70 lines of code.
Holy s..t, I suck! 
Well I care but I really don't. I solve it. 
:-]


*/


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;



int compareFunc (const void *a, const void *b)
{
  return ( *(int *)a - *(int *)b );
}


double functionMedian (int agentArray[], int ARRAY_SIZE)
{
  //Sort and output the array
  qsort(agentArray, ARRAY_SIZE, sizeof(int), compareFunc);

  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << agentArray[i] << "  ";
  }
  cout << endl;

  //NOTE: using the non integer 2.0 to produce a result of type "double".
  int middle = trunc(ARRAY_SIZE / 2.0);
  if (ARRAY_SIZE % 2 == 0)
  {
    //average of the two values in the middle.
    return ( (agentArray[ middle - 1 ] + agentArray[ middle ]) / 2.0 ); //NOTE: it is a zero based array.
  }
  else
  {
    //the value in the middle.
    return agentArray[ middle ]; //NOTE: it is a zero based array.
  }

}



int main()
{
  cout << "Find the agent with the highest median sales." << endl;


  const int NUM_AGENTS = 3;
  const int NUM_MONTHS = 12;
  int sales[NUM_AGENTS][NUM_MONTHS] =
  {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
  };

  int agentHighestMedian = 0;

  double highestMedian = 0.0;
  highestMedian = functionMedian(sales[0], NUM_MONTHS);

  for (int agent = 1; agent < NUM_AGENTS; agent++)
  {
    double agentMedian = functionMedian(sales[agent], NUM_MONTHS);
    if (agentMedian > highestMedian)
    {
      highestMedian = agentMedian;
      agentHighestMedian = agent;
    }
  }


  cout << "Agent " << agentHighestMedian + 1 << " is the agent with the highest median sales of: " << highestMedian << endl;

  cout << endl;
  return 0;
}
