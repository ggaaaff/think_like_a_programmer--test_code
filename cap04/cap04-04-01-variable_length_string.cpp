//2014.03.18 - 2014.03.19 - 2014.03.20 - 2014.06.14 Gustaf - CTG.


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
  newS[oldLength + 1] = 0; // "null terminator" at the end.


  // To avoid a memory leak, we have to deallocate the array in the heap
  // that our parameter s originally pointed to.
  delete[] s;

  s = newS;
}


void appendTester()
{
  cout << endl << "== Append Test" << endl;

  // WARNING: Every time you use the keyword "new", think about where and when
  // the corresponding "delete" will occur.

  // NOTICE: In this case the "delete" will happen inside the "append" function
  // that will be called later.

  arrayString a = new char[5];
  a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;

  append(a, '!');
  cout << a << endl;

  delete[] a; //2014.06.14 Free the memory allocated inside the call to append.


  // ---
  arrayString b = new char[1];
  b[0] = 0;

  append(b, '!');
  cout << b << endl;

  delete[] b; //2014.06.14 Free the memory allocated inside the call to append.
}



void concatenate(arrayString &s1, arrayString s2)
{
  int s1_OldLength = length(s1);
  int s2_Length    = length(s2);
  int s1_NewLength = s1_OldLength + s2_Length;


  arrayString newS = new char[s1_NewLength + 1]; // additional space for the "null terminator".

  // copy the characters from the two original strings to the new string.
  for (int i = 0; i < s1_OldLength; i++)
  {
    newS[i] = s1[i];
  }
  for (int i = 0; i < s2_Length; i++)
  {
    newS[i + s1_OldLength] = s2[i]; //s1_OldLength is an OFFSET.
  }

  newS[s1_NewLength] = 0; // "null terminator" at the end.

  // To avoid a memory leak, we have to deallocate the array in the heap
  // that our parameter s1 originally pointed to.
  delete[] s1;

  s1 = newS; // repoint the first parameter at the newly allocated string.
}


void concatenateTester()
{
  cout << endl << "== Concatenate Test" << endl;

  arrayString a = new char[5];
  a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;

  arrayString b = new char[4];
  b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;

  concatenate(a, b);
  cout << a << endl;

  //2014.06.14 Free the memory allocated inside the call to concatenate.
  delete[] a; 
  delete[] b; 


  // ---
  arrayString c = new char[5];
  c[0] = 't'; c[1] = 'e'; c[2] = 's'; c[3] = 't'; c[4] = 0;

  arrayString d = new char[1];
  d[0] = 0;

  concatenate(d, c);
  cout << c << endl << d << endl;

  // forces the output stream to display the raw value of the pointers.
  cout << (void *) c << endl << (void *) d << endl; 

  //2014.06.14 Free the memory allocated inside the call to concatenate.
  delete[] c; 
  delete[] d;   
}



char characterAt(arrayString s, int position)
{
  // NOTICE: Recall from Chapter 3 that if a pointer is assigned the address of an array,
  // we can access elements in the array using normal array notation
  return s[position];

  // WARNING: this code places the responsibility of validating 
  // the second parameter on the caller.
}


void characterAtTester()
{
  arrayString a = new char[5];
  a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;

  cout << endl << "== CharacterAt Test" << endl;
  cout << characterAt(a, 2) << endl;

  delete[] a;
}



int main()
{
  cout << "Variable-Length String Manipulation." << endl;

  appendTester();
  concatenateTester();
  characterAtTester();


  cout << endl;
  return 0;
}
