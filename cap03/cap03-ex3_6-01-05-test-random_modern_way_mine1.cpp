//2014.02.24 - 2014.02.26 Gustaf - CTG.


/* Testing generate a random number.

NOTE: Requieres to use the compiler option: -std=gnu++11



QUESTION 2014.02.24 
I do not know the reason, but everytime that it runs produce the same "random" numbers.
So this method is not so random for now.

ANSWER 2014.02.26 
Found the reason. The variable generator was not initialized.


OK - Test that it works.


*/



#include <iostream>
#include <random>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;


  // std::default_random_engine generator; //NOTE: wrong initialization.
  std::default_random_engine generator(std::random_device {}());


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
