//2014.02.24 Gustaf - CTG.


/* Testing generate a random number.

NOTE: Requieres to use the compiler option: -std=gnu++11

QUESTION
I do not know the reason, but everytime that it runs produce the same "random" numbers.
So this method is not so random for now.

*/



#include <iostream>
#include <random>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;


  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0, 9); //Range of the numbers.

  cout << "Random [0..9] - FOR 20 times" << endl;
  for (int i=0; i<20; ++i) {
    int number = distribution(generator);
    cout << number << " ";
  }
  cout << endl;


  cout << "Random [0..9] - FOR 10 times" << endl;
  for (int i=0; i<10; ++i) {
    int number = distribution(generator);
    cout << number << " ";
  }
  cout << endl;


  cout << "Random [0..9] - FOR 1 time" << endl;
  for (int i=0; i<1; ++i) {
    int number = distribution(generator);
    cout << number << " ";
  }
  cout << endl;


  cout << endl;
  return 0;
}
