//2014.02.24 - 2014.02.26 Gustaf - CTG.

/*
Source:
http://www.cplusplus.com/reference/random/uniform_int_distribution/

NOTE: Requieres to use the compiler option: -std=gnu++11


OK - Test that it works.


*/



// uniform_int_distribution
#include <iostream>
#include <random>

int main()
{
  const int nrolls = 10000; // number of experiments
  const int nstars = 95;    // maximum number of stars to distribute


  // std::default_random_engine generator; //NOTE: wrong initialization.
  std::default_random_engine generator(std::random_device {}());
  std::uniform_int_distribution<int> distribution(0,9);

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    int number = distribution(generator);
    ++p[number];  //NOTE: 2014.02.24 I can't identify this trick!!
            //2014.02.26 Got it, it is an increment of the value referenced by the index "number".
            //This same trick is used to form the histogram in: /cap03-02-02-statistic_mode_optimized.cpp
  }

  std::cout << "uniform_int_distribution (0,9):" << std::endl;
  for (int i=0; i<10; ++i)
    std::cout << i << ": " << std::string(p[i]*nstars/nrolls,'*') << std::endl;

  return 0;
}
