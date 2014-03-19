//2014.03.18 - 2014.03.19 Gustaf - CTG.


/* P R O B L E M : V A R I A B L E - L E N G T H  S T R I N G  M A N I P U L A T I O N

Write heap-based implementations for three required string functions:

  - append
  This function takes a string and a character and appends the character
  to the end of the string.

  - concatenate
  This function takes two strings and appends the characters of the
  second string onto the first.

  - characterAt
  This function takes a string and a number and returns the character
  at that position in the string (with the first character in the string numbered zero).


  Write the code with the assumption that characterAt will be called frequently,
  while the other two functions will be called relatively seldom. The relative efficiency of
  the operations should reflect the calling frequency.



=== PLAN ===

-
-

*/



#include <iostream>

using namespace std;



// We know we’re going to be dynamically creating our arrays,
// so we need to make our string type a pointer to char.
typedef char *arrayString;


int length(arrayString s)
{
  // Determine the length of a string array. 
  int count = 0;
  while (s[count] != 0) // not includes the "null terminator".
  {
    count++;
  }
  return count;
}



char characterAt(arrayString s, int position)
{
  // NOTICE: Recall from Chapter 3 that if a pointer is assigned the address of an array,
  // we can access elements in the array using normal array notation
  return s[position];
}



void append(arrayString &s, char c)
{
  // NOTICE: The arrayString parameter had to be a reference (&)
  // because the function is going to create a new array in the heap.


  int oldLength = length(s);
  // NOW "oldLength" has the number of legitimate characters in the array
  // (not including the terminating null character).


  // new array allocated.
  // +2 is the additional space for the "appended character" and the "null terminator".
  arrayString newS = new char[oldLength + 2];


  // copy all of the legitimate characters from the old array to the new.
  for (int i = 0; i < oldLength; i++)
  {
    newS[i] = s[i];
  }

  newS[oldLength]     = c; // "appended character"
  newS[oldLength + 1] = 0; // "null terminator"


  // To avoid a memory leak, we have to deallocate the array in the heap
  // that our parameter s originally pointed to.
  delete[] s;

  s = newS;
}



void appendTester()
{
  // WARNING: Every time you use the keyword "new", think about where and when
  // the corresponding "delete" will occur.
  //
  // NOTICE: In this case the "delete" will happen inside the "append" function
  // that will be called later.
  arrayString a = new char[5];

  a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
  append(a, '!');
  cout << a << endl;


  // ---
  arrayString b = new char[1];
  b[0] = 0;
  append(b, '!');
  cout << b << endl;
}


int main()
{
  cout << "Variable-Length String Manipulation." << endl;


  appendTester();



  cout << endl;
  return 0;
}
