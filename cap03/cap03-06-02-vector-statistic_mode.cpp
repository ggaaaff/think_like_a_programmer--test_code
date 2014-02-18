//2014.02.17 Gustaf - CTG.


/*
Consider another variant where the
user begins by entering survey responses without telling us the number of
responses, indicating that there are no more responses by entering a –1
(a data entry method known as a sentinel).


NOTE: The vector class from the C++ standard template library acts like an
array but grows as necessary. Once declared and initialized, the vector can
be processed exactly the same way as an array.

*/


#include <iostream>
#include <vector>

using namespace std;



int main()
{
  cout << "Finding the MODE (input values between 1 and 10) \n";

  //Creating the vector.
  vector<int> surveyData; 
  surveyData.reserve(30);


  //-- Initializing the vector.
  int surveyResponse;
  cout << "Enter next survey response or -1 to end: ";
  cin >> surveyResponse;
  while (surveyResponse != -1)
  {
    surveyData.push_back(surveyResponse);
    cout << "Enter next survey response or -1 to end: ";
    cin >> surveyResponse;
  }

  //-- Creating the histogram.
  int vectorSize = surveyData.size();
  const int MAX_RESPONSE = 10;
  int histogram[MAX_RESPONSE];
  for (int i = 0; i < MAX_RESPONSE; i++)
  {
    histogram[i] = 0;
  }

  for (int i = 0; i < vectorSize; i++)
  {
    histogram[surveyData[i] - 1]++;
  }

  //-- Calculating the mode.
  int mostFrequent = 0;
  for (int i = 1; i < MAX_RESPONSE; i++)
  {
    if (histogram[i] > histogram[mostFrequent]) mostFrequent = i;
  }
  mostFrequent++;


  cout << mostFrequent << " is the MODE \n";

  cout << "\n";
  return 0;
}
