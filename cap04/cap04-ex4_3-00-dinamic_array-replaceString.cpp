//2014.03.28 Gustaf - CTG.


/* EXERCISE 4-3 :

For our dynamically allocated strings, create a function replaceString that takes
three parameters, each of type arrayString: source, target, and replaceText.

The function replaces every occurrence of target in source with replaceText.

For example,
  if source points to an array containing "abcdabee",
  target points to "ab",
  and replaceText points to "xyz",
  then when the function ends, source should point to an array containing "xyzcdxyzee".


=== PLAN ===

- Diagram of the example.
- Traverse (go over) the SOURCE string and identify the initial and final positions in the TARGET string.


*/



#include <iostream>

using namespace std;


typedef char *arrayString;



int main()
{
  cout << "Variable-Length String Manipulation. REPLACE" << endl;



  cout << endl;
  return 0;
}
