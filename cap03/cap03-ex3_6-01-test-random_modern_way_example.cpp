//2014.02.24 Gustaf - CTG.

/*
Source:
http://www.cplusplus.com/reference/random/uniform_int_distribution/

NOTE: Requieres to use the compiler option: -std=gnu++11

*/



// uniform_int_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls = 10000; // number of experiments
  const int nstars = 95;    // maximum number of stars to distribute

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,9);

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    int number = distribution(generator);
    ++p[number];  //NOTE: 2014.02.24 I can't identify this trick!!
  }

  std::cout << "uniform_int_distribution (0,9):" << std::endl;
  for (int i=0; i<10; ++i)
    std::cout << i << ": " << std::string(p[i]*nstars/nrolls,'*') << std::endl;

  return 0;
}
