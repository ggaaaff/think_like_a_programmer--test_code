//2014.02.17 Gustaf - CTG.


/*
Suppose the mode problem was modified so that we didn’t know ahead of time how many survey
responses we would have, but that number came to the program as user input.

*/




#include <iostream>
#include <cstdlib>

using namespace std;

/*BASED IN: cap03-02-01-statistic_mode.cpp
*/


int compareFunc(const void *voidA, const void *voidB)
{
  int *intA = (int *)(voidA);
  int *intB = (int *)(voidB);
  return *intA - *intB;
}



int main()
{
  cout << "Finding the MODE (any input values) \n";

  //-- Obtaining the data
  int ARRAY_SIZE;
  cout << "Number of survey responses: ";
  cin >> ARRAY_SIZE;
  int *surveyData = new int[ARRAY_SIZE]; //Pointer initialized dinamically as an array.
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    cout << "Survey response " << i + 1 << ": ";
    cin >> surveyData[i]; //Accessing the pointer as an array.
  }


  //-- Processing the data
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




  //-- Deallocate array
  delete[] surveyData; 

  cout << "\n";
  return 0;
}
