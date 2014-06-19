//2014.03.27 Gustaf - CTG.


/* EXERCISE 4-2 :

For our dynamically allocated strings, create a function substring that takes
three parameters: an arrayString, a starting position integer, and an integer
length of characters.

  The function returns a pointer to a new dynamically allocated string array.

  This string array contains the characters in the original
  string, starting at the specified position for the specified length.

  The original string is unaffected by the operation.

So if the original string was abcdefg,
the position was 3, and the length was 4, then the new string would contain cdef.



=== PLAN ===

OK - Reuse code from: cap04-04-01-variable_length_string.cpp
OK - Substring function.
    ok- Diagram in LibreOffice Calc.
    ok- Special cases.

*/



#include <iostream>


using namespace std;



typedef char *arrayString;

int lengthFunct(arrayString s)
{
  // Determine the length of a string array.

  int count = 0;
  while (s[count] != 0) // not includes the "null terminator".
  {
    count++;
  }
  return count;
}


arrayString substringFunct(arrayString s, int position, int lengthDest)
{
  // NOTICE: Recall from Chapter 3 that if a pointer is assigned the address of an array,
  // we can access elements in the array using normal array notation

  arrayString newS = new char[lengthDest + 1];
  for (int i = 0; i < lengthDest; i++)
  {
    newS[i] = s[ (position - 1) + i];
  }
  newS[lengthDest + 1] = 0;

  return newS;
}


void substringTester()
{
  arrayString a = new char[8];
  a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd'; a[4] = 'e'; a[5] = 'f'; a[6] = 'g'; a[7] = 0;
  cout << a << endl;
  
  // 2014.06.19 Gustaf. A doubt.
  // 
  // Today I realized that I declared variable "a" with a size of 6 (new char [6]), 
  // but I was initializing it with 8 values.
  // Then I tested with a size of 1 (new char [1]) and I realize the initialization was OK.
  // What does this means: 
  //   A case of memory corruption? Or is this the way dinamyc arrays works?


  arrayString b = new char[5];
  arrayString c = new char[5];
  arrayString d = new char[5];
  arrayString e = new char[5];


  b = substringFunct(a, 3, 4); // Normal case.
  cout << b << endl;
  delete b;

  c = substringFunct(a, 6, 4); // Special case, longer length.
  cout << c << endl;
  delete c;

  d = substringFunct(a, 7, 4); // Special case, longer length.
  cout << d << endl;
  delete d;

  e = substringFunct(a, 18, 4); //Extreme case, position out of limits.
  cout << e << endl;
  delete e;


  delete a;
}



int main()
{
  cout << "Variable-Length String Manipulation. SUBSTRING" << endl;

  substringTester();


  cout << endl;
  return 0;
}
