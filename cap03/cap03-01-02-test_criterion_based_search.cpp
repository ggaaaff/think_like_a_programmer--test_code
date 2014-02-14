//2014.02.09 Gustaf - CTG.


#include <iostream>
#include <string>

using namespace std;


int main()
{
  cout << "TEST Criterion-Based Search \n";


  const int ARRAY_SIZE = 10;
  int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 30987, -287, 1};
  int highestValue = intArray[0];
  for (int i = 1; i < ARRAY_SIZE; i++)
  {
    if (intArray[i] > highestValue) highestValue = intArray[i];
  }


  cout << highestValue << " Highest Value \n";
  return 0;
}
