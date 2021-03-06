//2014.03.13 - 2014.06.17 Gustaf - CTG.


#include <iostream>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl << endl;


  // ------
  int *intPointer;  // declares intPointer as a pointer to an int.

  int *variable1, variable2, variable3;  // variable1 is a pointer to an int,
  // WARNING: variable2 is just an int.



  // An ampersand in front of a variable acts as the address-of operator.
  variable1 = &variable2; // assign the address of variable2 to variable1.

  // assign the value of one pointer variable to another directly.
  cout << "Test to clarify the concept." << endl; //2014.06.17 Gustaf.

  cout << " intPointer Before1: " << intPointer << " - " << *intPointer << endl;
  intPointer = &variable3; // if I delete this line, then "*intPointer = 10000;" 
                           // generates the error: "Segmentation fault (core dumped)".
  cout << " intPointer Before2: " << intPointer << " - " << *intPointer << endl;
  *intPointer = 10000;
  cout << " intPointer After:   " << intPointer << " - " << *intPointer << endl << endl;

  cout << " variable1 Before: " << variable1 << " - " << *variable1 << endl;
  *variable1 = 9999;
  cout << " variable1 After:  " << variable1 << " - " << *variable1 << endl << endl;


  intPointer = variable1; // direct assign of address.
  cout << " intPointer: " << intPointer << " - " << *intPointer << endl;
  cout << " variable1:  " << variable1  << " - " << *variable1 << endl << endl;


  // ------
  // allocate memory during runtime that can be accessed only through a pointer.
  // This is accomplished with the new operator:
  double *doublePointer = new double;

  // Accessing the memory at the other end of the pointer is known as dereferencing.
  *doublePointer = 35.4; // assign a value to the double allocated.
  double localDouble = *doublePointer; // copy the value from this memory location to the variable localDouble


  // To deallocate memory allocated with new, once we no longer need it, we use the keyword delete:
  delete doublePointer;


  cout << endl;
  return 0;
}
