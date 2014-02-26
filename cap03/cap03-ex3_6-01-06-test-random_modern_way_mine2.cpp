//2014.02.26 Gustaf - CTG.


/*
Source:
http://stackoverflow.com/questions/9484588/c-generating-random-numbers?rq=1

NOTE: Requieres to use the compiler option: -std=gnu++11


OK - Test that it works.

*/


#include <random>
#include <iostream>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;


  default_random_engine eng(random_device {}()); //Initialize


  uniform_int_distribution<> dist(1, 60);
  for (int i = 0; i < 20; ++i)
    cout << dist(eng) << " ";
  cout << endl;


  uniform_int_distribution<> dist2(1, 30);
  for (int i = 0; i < 10; ++i)
    cout << dist2(eng) << " ";
  cout << endl;


  cout << endl;
  return 0;
}
