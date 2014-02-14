//2014.01.16 Gustaf - CTG.

/*

P R O B L E M : A  S I D E W A Y S  T R I A N GL E
Write a program that uses only two output statements, cout << "#" and cout << "\n",
to produce a pattern of hash symbols shaped like a sideways triangle:
#
##
###
####
###
##
#

*/

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;



/*
Primera forma facilista en que lo resolví.
Luego leí la sugerencia del libro para llegar al truco de la 
condición especial del loop:
      for (int row = 1;  row <= 7; row++) {
          cout << 4 - ( abs(4 - row) ) << "\n";
      }



int main()
{
  for (int i = 1; i <= 3; i++) {
    for (int hashNum = 1; hashNum <= i; hashNum++) {
      cout << "#";
    }
    cout << "\n";    
  }

  for (int i = 1; i <= 4; i++) {
    for (int hashNum = 1; hashNum <= 5-i; hashNum++) {
      cout << "#";
    }
    cout << "\n";    
  }


  return 0;
}

*/


int main()
{
  for (int i = 1; i <= 7; i++) {
    for (int hashNum = 1; hashNum <=  (4 - (abs(4 - i))); hashNum++) {
      cout << "#";
    }
    cout << "\n";    
  }

  return 0;
}

