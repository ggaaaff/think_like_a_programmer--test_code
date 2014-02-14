//2014.01.26 Gustaf - CTG.

/*

Using only single-character output statements that output a hash mark,
a space, or an end-of-line, write a program that produces the following shape:


#____________#  
_##________##_  
__###____###__  
___########___  
___########___
__###____###__
_##________##_
#____________#



My initial idea expressed as numbers: index |    space | hash | space | hash | space
| 1 |    0 | 1 | 12 | 1 | 0 | 
| 2 |    1 | 2 |  8 | 2 | 1 | 
| 3 |    2 | 3 |  4 | 3 | 2 | 
| 4 |    3 | 4 |  0 | 4 | 3 | 

| 5 |    3 | 4 |  0 | 4 | 3 | 
| 6 |    2 | 3 |  4 | 3 | 2 | 
| 7 |    1 | 2 |  8 | 2 | 1 | 
| 8 |    0 | 1 | 12 | 1 | 0 | 


==== PLAN ====
OK - Output 8 lines with the pattern: 2 space | 3 hash | 12 space | 3 hash | 2 space

OK - Test sequences of numbers.

OK - Output the correct number of hash each line.
OK - Output the correct number of space each line.

*/


#include <iostream>

using std::cin;
using std::cout;


int main()
{
  cout << "shapes with hash, space and end-of-line. \n";

/* UPPER HALF
index |    space | hash | space | hash | space

| 1 |    0 | 1 | 12 | 1 | 0 | 
| 2 |    1 | 2 |  8 | 2 | 1 | 
| 3 |    2 | 3 |  4 | 3 | 2 | 
| 4 |    3 | 4 |  0 | 4 | 3 | 

Formula for 2nd space depends on the sum of space and hash column before this space.
(7char - (space + hash) )* 2

(7 - (0 + 1) ) *2 = 12
(7 - (1 + 2) ) *2 = 8
(7 - (2 + 3) ) *2 = 4
(7 - (3 + 4) ) *2 = 0

*/

  for (int i = 1; i <= 4; i++)
  {
    for (int space = 1; space <= (i-1); space++)
    {
      cout << "_";
    }

    for (int hashNum = 1; hashNum <= (i); hashNum++)
    {
      cout << "#";
    }

    for (int space = 1; space <= ( 2* (7- ((i-1)+i)) ); space++) 
    {
      cout << "_";
    }

    for (int hashNum = 1; hashNum <= (i); hashNum++)
    {
      cout << "#";
    }

    for (int space = 1; space <= (i-1); space++)
    {
      cout << "_";
    }

    cout << "\n";
  }//end for upper half



/* LOWER HALF
index |    space | hash | space | hash | space

| 1 |    3 | 4 |  0 | 4 | 3 | 
| 2 |    2 | 3 |  4 | 3 | 2 | 
| 3 |    1 | 2 |  8 | 2 | 1 | 
| 4 |    0 | 1 | 12 | 1 | 0 | 

*/

  for (int i = 1; i <= 4; i++)
  {
    for (int space = 1; space <= (4-i); space++)
    {
      cout << "_";
    }

    for (int hashNum = 1; hashNum <= (5-i); hashNum++)
    {
      cout << "#";
    }

    for (int space = 1; space <= ( 2* (7- ((4-i)+(5-i))) ); space++)
    {
      cout << "_";
    }

    for (int hashNum = 1; hashNum <= (5-i); hashNum++)
    {
      cout << "#";
    }

    for (int space = 1; space <= (4-i); space++)
    {
      cout << "_";
    }

    cout << "\n";
  }//end for lower half



  return 0;
}
