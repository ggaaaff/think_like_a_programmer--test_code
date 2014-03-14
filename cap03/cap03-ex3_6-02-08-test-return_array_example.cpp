//2014.03.06 Gustaf - CTG.


/*

------Information

Sample of a function returning an array:
http://www.cplusplus.com/forum/beginner/3823/

    char* retArray()
    {
      char* letters = new char[ 9 ];  // 8 characters + null terminator
      char_traits <char> ::copy( letters, "abcdefgh", 9 );  // same as strcpy()
      return letters;
    }



http://stackoverflow.com/questions/5660527/how-do-i-return-a-char-array-from-a-function
    Best as an out parameter:

    void testfunc(char* outStr){
      char str[10];
      for(int i=0; i < 10; ++i){
        outStr[i] = str[i];
      }
    }
    Called with

    int main(){
      char myStr[10];
      testfunc(myStr);
      // myStr is now filled
    }



*/



#include <iostream>

using namespace std;



char *returnArray()
{

  char *letters = new char[ 3 ];

  letters[0] = 'q';
  letters[1] = 'e';
  letters[2] = 'r';

  return letters;
}


void paramArray(char *outStr)
{
  outStr[0] = 'A';
  outStr[1] = 'B';
  outStr[2] = 'C';
}



int main()
{
  cout << "Hello world - Linux Mint." << endl;

  // Function returning array
  char *myarr = new char[3];
  myarr =  returnArray();

  cout << myarr[0];
  cout << myarr[1];
  cout << myarr[2];
  cout << endl;

  delete myarr; // 2014.03.14 Added after reading about pointers.


  // Array as parameter
  char myStr[3];
  paramArray(myStr);

  cout << myStr[0];
  cout << myStr[1];
  cout << myStr[2];
  cout << endl;


  cout << endl;
  return 0;
}
