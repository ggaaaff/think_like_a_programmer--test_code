//2014.03.14 Gustaf - CTG.


#include <iostream>


using namespace std;



// we can pass a pointer to a block of memory (instead of passing a copy of the block)
// using reference parameters.
// The ampersand (&) appears between the type and the name in the formal parameter list.
void refParamFunction (int &x)
{
  x = 10; // Affects the external variable.
}



// We can signal that we are using a reference parameter for performance, not its output,
// by using the const keyword.
int const_refParamFunction (const int &x)
{
  // By prefixing the word const in the declaration of the reference parameter x,
  // const_refParamFunction will receive a reference to the argument passed in the
  // call but will be unable to modify the value in that argument,
  // just like any other const parameter.

  // x = 11; // If active it gives an error.
}


// 2014.03.14 I CAN NOT UNDERSTAND WHY: If I put "&outStr" instead of "*outStr" it generates an ERROR.
void returnParamArray(char *outStr) //OK
// void returnParamArray(char &outStr) //ERROR
{
  outStr[0] = 'A';
  outStr[1] = 'B';
  outStr[2] = 'C';
}


int main()
{
  cout << "Hello world - Linux Mint." << endl;

  // Memory sharing - reference parameter
  int number = 5;
  refParamFunction(number);
  cout << number << endl;


  // Memory sharing - reference parameter for performance
  const_refParamFunction (number);



  // Memory sharing
  char myStr[3];
  returnParamArray(myStr);

  cout << myStr[0];
  cout << myStr[1];
  cout << myStr[2];
  cout << endl;


  cout << endl;
  return 0;
}
