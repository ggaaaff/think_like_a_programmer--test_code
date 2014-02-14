//2014.02.11 Gustaf - CTG.


/*
P R O B L E M : F I N D I N G  T H E  M O D E
In statistics, the mode of a set of values is the value that appears most often. Write
code that processes an array of survey data, where survey takers have responded to
a question with a number in the range 1–10, to determine the mode of the data set.
For our purpose, if multiple modes exist, any may be chosen.


*/


#include <iostream>
#include <cstdlib>

using namespace std;




int main()
{
  cout << "Finding the MODE \n";

  const int ARRAY_SIZE = 12;
  int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};


  /* Create the histogram */
  const int MAX_RESPONSE = 10;
  int histogram[MAX_RESPONSE]; //{1 2 3 4 5 6 7 8 9 10}

  //Initialize to zero.
  for (int i = 0; i < MAX_RESPONSE; i++)
  {
    histogram[i] = 0;
  }

  //Fill in the array with the number of times each value (from 1 to 10) is repeated.
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    histogram[surveyData[i] - 1]++; //NOTE: the -1 is because the array is zero based.
  }


  /* Find the largest value in the histogram array */
  int mostFrequent = 0;
  for (int i = 1; i < MAX_RESPONSE; i++)
  {
    if (histogram[i] > histogram[mostFrequent])
      mostFrequent = i;
  }
  mostFrequent++; //NOTE: the +1 is because the array is zero based.


  cout << mostFrequent << " is the MODE \n";
  return 0;
}
