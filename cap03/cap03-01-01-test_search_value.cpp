//2014.02.09 Gustaf - CTG.


#include <iostream>
#include <string>

using namespace std;


int main()
{
  cout << "TEST Searching for a Specific Value \n";


  const int ARRAY_SIZE = 10;
  int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 30987, -287, 1};
  int targetValue = 12;
  int targetPos = 0;
  while ((intArray[targetPos] != targetValue) && (targetPos < ARRAY_SIZE))
    targetPos++;

  if (targetPos < ARRAY_SIZE)
  {
    cout << targetValue << " Target Value Finded \n";
  }
  else
  {
    cout << targetValue << " Target Value NOT Finded \n";
  }

  return 0;
}
