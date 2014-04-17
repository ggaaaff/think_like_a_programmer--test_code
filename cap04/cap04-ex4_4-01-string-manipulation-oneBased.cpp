//2014.04.16 Gustaf - CTG.


/* EXERCISE 4-4 :

Change the implementation of our strings such that location[0] in the array
stores the size of the array, rather than using a null-character terminator.

  location[0] stores the size of the array.
  location[1] stores the first actual character in the string.


Implement each of the three functions, append, concatenate, and characterAt,
taking advantage of the stored size information whenever possible.


Because we’ll no longer be using the null-termination convention expected by the
standard output stream, you’ll need to write your own output function that
loops through its string parameter, displaying the characters.



=== PLAN ===

OK - output function.
OK - characterAt function.
OK - append function.
OK - concatenate function.

*/



#include <iostream>

using namespace std;


typedef char *arrayString;




void outputFunction(arrayString s)
{
  for (int i = 1; i <= s[0]; ++i)
  {
    cout << s[i];
  }
  cout << endl;
}


char characterAt(arrayString s, int position)
{
  // NOTICE: Recall from Chapter 3 that if a pointer is assigned the address of an array,
  // we can access elements in the array using normal array notation
  return s[position];

  // WARNING: this code places the responsibility of validating
  // the second parameter on the caller.
}


void appendOneChar(arrayString &s, char c)
{
  // NOTICE: The arrayString parameter had to be a reference (&)
  // because the function is going to create a new array in the heap.


  int oldLength = s[0];
  int newLength = 1 + oldLength; // additional space for the index at the beginning.


  // new array allocated.
  arrayString newS = new char[newLength];


  // copy all of the legitimate characters from the old array to the new.
  for (int i = 1; i <= oldLength; i++)
  {
    newS[i] = s[i];
  }
  newS[newLength] = c; // "appended character".

  newS[0] = newLength; // New length of string.


  // To avoid a memory leak, we have to deallocate the array in the heap
  // that our parameter s originally pointed to.
  delete[] s;

  s = newS;
}



void concatenate(arrayString &s1, arrayString s2)
{
  int s1_OldLength = s1[0];
  int s2_Length    = s2[0];
  int s1_NewLength = s1_OldLength + s2_Length;


  arrayString newS = new char[1 + s1_NewLength]; // additional space for the index at the beginning.

  // copy the characters from the two original strings to the new string.
  for (int i = 1; i <= s1_OldLength; i++)
  {
    newS[i] = s1[i];
  }
  for (int i = 1; i <= s2_Length; i++)
  {
    newS[s1_OldLength + i] = s2[i];
  }

  newS[0] = s1_NewLength; // New length of the string at the beginning.


  // To avoid a memory leak, we have to deallocate the array in the heap
  // that our parameter s1 originally pointed to.
  delete[] s1;

  s1 = newS; // repoint the first parameter at the newly allocated string.
}



int main()
{
  cout << "Variable-Length String Manipulation." << endl;


  // --
  arrayString a = new char[4];
  a[0] = 3; a[1] = 'a'; a[2] = 'b'; a[3] = 'c';

  cout << "Initial string    : ";
  outputFunction(a);


  cout << "Second character  : " <<  characterAt(a, 2) << endl;


  appendOneChar(a, 'D');
  cout << "Append D          : ";
  outputFunction(a);
  cout << endl;



  // --
  cout << "Special case (empty string)" << endl;

  arrayString b = new char[1];
  b[0] = 0;

  appendOneChar(b, 'A');
  cout << "Append A  : ";
  outputFunction(b);
  cout << endl;


  // ---
  cout << "Concatenate two strings" << endl;

  arrayString c = new char[4];
  c[0] = 3; c[1] = 'a'; c[2] = 'b'; c[3] = 'c';

  arrayString d = new char[3];
  d[0] = 2; d[1] = 'D'; d[2] = 'E';

  // arrayString d = new char[1];
  // d[0] = 0;

  outputFunction(c);
  outputFunction(d);

  concatenate(d, c);
  outputFunction(d);



  // Free memory
  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;


  cout << endl;
  return 0;
}
