/*
To run, compile and execute a C++ program on Linux Mint /Ubuntu.

First install the g++ compiler... 
    sudo apt-get install g++ 

...and then follow the steps:
Open terminal ( Ctrl+Alt+t) 

Locate the program file on terminal 
    g++ programname -o outputfilename
		
g++ helloworld.cpp -o hello
./hello


*/


//helloworld.cpp
//2014.02.19 Gustaf - CTG.


#include <iostream>
#include <string>

using namespace std;



int main()
{
  cout << "Hello world - Linux Mint." << endl;

  cout << endl;
  return 0;
}

