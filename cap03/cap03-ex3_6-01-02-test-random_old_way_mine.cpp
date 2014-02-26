//2014.02.24 - 2014.02.25 - 2014.02.26 Gustaf - CTG.


/* OBJECTIVE: Generate a random number.


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


  
  // If you seed inside the loops, the random does not work and the output will be the same number.
  srand(time(NULL)); // VERY IMPORTANT NOTE: KEEP this seed out of the loops.


  for (int i = 0; i < 20; ++i)
  {
    // randomNumber = lowest + rand() % range
    int randomNumber = 0 + rand() % (25 - 0);
    cout << randomNumber;
    cout << " ";
  }
  cout << endl;


  for (int i = 0; i < 20; ++i)
  {
    //range = (highest - lowest) + 1;
    //random_integer = lowest + int(range * (rand() / (RAND_MAX + 1.0)));
    int randomNumber = 0 + int(26 * (rand() / (RAND_MAX + 1.0)) );
    cout << randomNumber;
    cout << " ";
  }

  cout << endl;
  return 0;
}
