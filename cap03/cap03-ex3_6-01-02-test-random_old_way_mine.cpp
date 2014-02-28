//2014.02.24 - 2014.02.25 - 2014.02.26 Gustaf - CTG.


/* OBJECTIVE: Generate a random number.


Source
http://stackoverflow.com/questions/12580820/random-number-between-1-to-10-using-c

  srand(time(NULL))
  randomNumber = lowest + rand() % range


The output dependes on the RANGE = (highest - lowest) + 1;
Examples:

  RANGE = 0
  warning: division by zero [-Wdiv-by-zero]

  RANGE = 1
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

  RANGE = 2
  0 1 1 0 1 0 0 0 1 0 1 1 1 0 1 0 1 1 1 0 

  RANGE = 3
  0 1 1 2 2 1 0 2 0 1 0 1 0 0 0 1 0 1 2 2 

  RANGE = 4
  0 2 3 2 0 2 0 1 1 3 3 3 3 1 3 2 0 3 2 0 

  RANGE = 10
  5 9 1 2 8 4 2 5 1 7 6 2 6 6 4 8 1 0 9 2 

  RANGE = 11
  8 7 4 10 3 9 8 3 8 7 10 0 4 3 9 8 1 8 6 9 



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
    // range = (highest - lowest) + 1;
    // randomNumber = lowest + rand() % range
    int randomNumber = 0 + rand() % 10;
    cout << randomNumber;
    cout << " ";
  }
  cout << endl;


  for (int i = 0; i < 20; ++i)
  {
    //range = (highest - lowest) + 1;
    //random_integer = lowest + int(range * (rand() / (RAND_MAX + 1.0)));
    int randomNumber = 0 + int(11 * (rand() / (RAND_MAX + 1.0)) );
    cout << randomNumber;
    cout << " ";
  }

  cout << endl;
  return 0;
}
