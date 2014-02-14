//2014.01.16 Gustaf - CTG.

/*

P R O B L E M : H A L F  O F  A  S Q U A R E
Write a program that uses only two output statements, cout << "#" and cout << "\n",
to produce a pattern of hash symbols shaped like half of a perfect 5 x 5 square (or a right triangle):
#####
####
###
##
#

*/

#include <iostream>

using std::cin;
using std::cout;


int main()
{
  for (int i = 1; i <= 5; i++) {
    for (int hashNum = 1; hashNum <= 6-i; hashNum++) {
      cout << "#";
    }
    cout << "\n";    
  }


  return 0;
}


