//2014.02.24 - 2014.02.25 Gustaf - CTG.


/* OBJECTIVE :
Generate a random number.


Source
http://stackoverflow.com/questions/12580820/random-number-between-1-to-10-using-c

  srand(time(NULL))
  randomNumber = lowest + rand() % range


=== PLAN ===

OK - Test the code.


*/


#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;


  srand(time(NULL));
  int randomNumber = 0 + rand() % (25 - 0);
  cout << randomNumber;
  cout << endl;
  cout << endl;


  for (int i = 0; i < 20; ++i)
  {
    srand(time(NULL));

    TODO These test does not work inside this loop.

    // randomNumber = lowest + rand() % range
    // int randomNumber = 0 + rand() % (25 - 0);
    // cout << randomNumber;
    // cout << " ";


    // randomNumber = lowest + int(range * (rand() / (RAND_MAX + 1.0)))
    int randomNumber = 0 + int(25 * (rand() / (RAND_MAX + 1.0)));
    cout << randomNumber;
    cout << " ";
  }

  cout << endl;
  return 0;
}
