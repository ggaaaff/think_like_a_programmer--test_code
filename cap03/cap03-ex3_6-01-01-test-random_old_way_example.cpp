//2014.02.25 Gustaf - CTG.


/*
Source:
http://stackoverflow.com/questions/9484588/c-generating-random-numbers?rq=1

OK - Test that it works.

*/


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  srand((unsigned)time(0));
  int random_integer;
  int lowest = 1, highest = 10;
  int range = (highest - lowest) + 1;
  for (int index = 0; index < 20; index++)
  {
    random_integer = lowest + int(range * (rand() / (RAND_MAX + 1.0)));

    cout << random_integer << " ";
  }

  cout << endl;
  return 0;
}
