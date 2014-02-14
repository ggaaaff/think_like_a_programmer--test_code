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



int compareFunc(const void *voidA, const void *voidB)
{
  int *intA = (int *)(voidA);
  int *intB = (int *)(voidB);
  return *intA - *intB;
}



int main()
{
  cout << "Finding the MODE \n";

  const int ARRAY_SIZE = 12;
  int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};


  /*Sorting the array in order to organize the data in groups*/
  qsort(surveyData, ARRAY_SIZE, sizeof(int), compareFunc);


  /*Finding the mode*/
  int mostFrequent;
  int highestFrequency = 0;
  int currentFrequency = 0;
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    currentFrequency++;

    // if (surveyData[i] is the last occurence of the current grouped value)
    if ( (i == ARRAY_SIZE - 1) || (surveyData[i] != surveyData[i + 1]) ) /*End of array OR change of grouped value*/
    {
      if (currentFrequency > highestFrequency)
      {
        highestFrequency = currentFrequency;
        mostFrequent = surveyData[i];
      }
      currentFrequency = 0;
    }
  }


  cout << mostFrequent << " is the MODE \n";
  return 0;
}
