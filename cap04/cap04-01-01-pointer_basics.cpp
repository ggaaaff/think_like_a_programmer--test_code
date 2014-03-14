//2014.03.13 Gustaf - CTG.


#include <iostream>

using namespace std;


int main()
{
  cout << "Hello world - Linux Mint." << endl;


  // ------
  int *intPointer;  // declares intPointer as a pointer to an int.

  int *variable1, variable2;  // variable1 is a pointer to an int,
  // WARNING: variable2 is just an int.



  // An ampersand in front of a variable acts as the address-of operator.
  variable1 = &variable2; // assign the address of variable2 to variable1.

  // assign the value of one pointer variable to another directly.
  intPointer = variable1;



  // ------
  // allocate memory during runtime that can be accessed only through a pointer.
  // This is accomplished with the new operator:
  double *doublePointer = new double;

  // Accessing the memory at the other end of the pointer is known as dereferencing.
  *doublePointer = 35.4; // assign a value to the double allocated.
  double localDouble = *doublePointer; // copy the value from this memory location to the variable localDouble


  // To deallocate memory allocated with new, once we no longer need it, we use the keyword delete:
  delete doublePointer;



  // ------
  // we can pass a pointer to a block of memory instead of passing a copy of the block using reference parameters.
  void refParamFunction (int &x)
  {
    x = 10;
  }
  int number = 5;
  refParamFunction(number);
  cout << number << endl;



  cout << endl;
  return 0;
}
