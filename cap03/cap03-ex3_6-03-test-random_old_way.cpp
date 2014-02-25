//2014.02.24 Gustaf - CTG.


/* OBJECTIVE :
Generate a random number.


Source
http://stackoverflow.com/questions/12580820/random-number-between-1-to-10-using-c

  srand(time(NULL))
  random_integer = lowest + rand() % range


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
  return 0;
}
