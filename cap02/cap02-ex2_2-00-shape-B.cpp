//2014.01.24 Gustaf - CTG.

/*

Using only single-character output statements that output a hash mark,
a space, or an end-of-line, write a program that produces the following shape:
   ##
  ####
 ######
########
########
 ######
  ####
   ##


My initial idea expressed as numbers: index |    space | hash | space
| 1 |    3 | 2 | 3
| 2 |    2 | 4 | 2
| 3 |    1 | 6 | 1
| 4 |    0 | 8 | 0

| 5 |    0 | 8 | 0
| 6 |    1 | 6 | 1
| 7 |    2 | 4 | 2
| 8 |    3 | 2 | 3


==== PLAN ====
OK - Output 8 hash in each line.
OK - Output a single space in each line at the begining.
OK - Output a single space in each line at the end.

OK - Test sequences of numbers.
  I can't came up with a single sequence where the central numbers are repeated, 
  so I'm going to divide the whole sequence by half.

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
index |    space | hash | space

| 1 |    3 | 2 | 3
| 2 |    2 | 4 | 2
| 3 |    1 | 6 | 1
| 4 |    0 | 8 | 0

*/

  for (int i = 1; i <= 4; i++)
  {
    for (int space = 1; space <= (4-i); space++)
    {
      cout << "_";
    }

    for (int hashNum = 1; hashNum <= (8 - ((4-i) * 2) ); hashNum++)
    {
      cout << "#";
    }

    for (int space = 1; space <= (4-i); space++)
    {
      cout << "_";
    }

    cout << "\n";
  }//end for upper half


/* LOWER HALF 
index |    space | hash | space

| 1 |    0 | 8 | 0
| 2 |    1 | 6 | 1
| 3 |    2 | 4 | 2
| 4 |    3 | 2 | 3

*/

  for (int i = 1; i <= 4; i++)
  {
    for (int space = 1; space <= (i - 1); space++)
    {
      cout << "_";
    }

    for (int hashNum = 1; hashNum <= (8 - ((i - 1) * 2) ); hashNum++)
    {
      cout << "#";
    }

    for (int space = 1; space <= (i - 1); space++)
    {
      cout << "_";
    }

    cout << "\n";
  }//end for, lower half

  return 0;
}
