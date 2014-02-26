//2014.02.26 Gustaf - CTG.


/*
Source:
http://stackoverflow.com/questions/9484588/c-generating-random-numbers?rq=1

NOTE: Requieres to use the compiler option: -std=gnu++11


OK - Test that it works.

*/


#include <random>
#include <iostream>

int main()
{
  std::default_random_engine eng(std::random_device {}());
  std::uniform_int_distribution<> dist(1, 10);

  for (int i = 0; i < 20; ++i)
    std::cout << dist(eng) << " ";

  std::cout << "\n";
}
