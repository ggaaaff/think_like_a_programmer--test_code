//2014.02.09 Gustaf - CTG.


#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
  cout << "Easy-to-Modify Sorting with Insertion Sort \n";

  const int ARRAY_SIZE = 10;
  int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};

  int start = 0;
  int end = ARRAY_SIZE - 1;
  for (int i = start + 1; i <= end; i++)
  {
    for (int j = i; j > start && intArray[j - 1] > intArray[j]; j--)
    {
      int temp = intArray[j - 1];
      intArray[j - 1] = intArray[j];
      intArray[j] = temp;
    }
  }


  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << intArray[i] << ", ";
  }

  cout << "\n";
  return 0;
}
