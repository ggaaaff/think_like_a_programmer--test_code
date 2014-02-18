//2014.02.17 Gustaf - CTG.


/*
If we are reading the data directly from the user, rather than being told that we
are starting with an array or other data collection, we may not need an array
for the survey data, only one for the histogram. Instead, we can process the
survey values as we read them.

*/


#include <iostream>
#include <string>

using namespace std;



int main()
{
  cout << "Finding the MODE (input values between 1 and 10) \n";

  const int MAX_RESPONSE = 10;

  //--Initializing histogram.
  int histogram[MAX_RESPONSE];
  for (int i = 0; i < MAX_RESPONSE; i++)
  {
    histogram[i] = 0;
  }

  //-- Getting the data and Creating the histogram.
  int surveyResponse;
  cout << "Enter next survey response or -1 to end: ";
  cin >> surveyResponse;
  while (surveyResponse != -1)
  {
    histogram[surveyResponse - 1]++;
    cout << "Enter next survey response or -1 to end: ";
    cin >> surveyResponse;
  }

  //-- Calculating the mode.
  int mostFrequent = 0;
  for (int i = 1; i < MAX_RESPONSE; i++)
  {
    if (histogram[i] > histogram[mostFrequent])
      mostFrequent = i;
  }
  mostFrequent++;


  cout << mostFrequent << " is the MODE \n";

  cout << "\n";
  return 0;
}
