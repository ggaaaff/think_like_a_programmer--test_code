//2014.07.16 Gustaf-37 - CTG.


/* EXERCISE / PROBLEM / OBJECTIVE :



=== PLAN ===

-
-

>> Copy and paste notes from the theory in chapter 5 of the book.


Because we are programming in C++ and therefore have the choice
between procedural and object-oriented programming, we’ll talk about good
class design, as well as when classes should and should not be used.

  An {object} should be a meaningful, closely knit collection of data and
  code that operates on that data.



## Review of Class Fundamentals


A {class} is a blueprint for constructing a particular package of code and data;

  each variable created according to a class’s blueprint is known as
  an {object} of that class.

  Code outside of a class that creates and uses an object of that class is known
  as a {client} of the class.


A "class declaration" names the class and lists all of the "members",
or items inside that class.

  Each item is either:
  a {data member} (a variable declared within the class).

  a {method} (also known as a {member function}), which is a function declared within the class.

    Member functions can include a special type called a {constructor},
    which has the same name as the class and is invoked implicitly
    when an object of the class is declared.


In addition to the normal attributes of a variable or function declaration
(such as type, and for functions, the parameter list),
each member also has an "access specifier", which indicates what functions can
access the member.

  A "public member" can be accessed by any code using the object:
    code inside the class,
    a client of the class,
    or code in a {subclass},
      which is a class that “inherits” all the code and data of an existing class.

  A "private member" can be accessed only by the code inside the class.

  "Protected members", which we’ll see briefly in this chapter,
  are similar to private members, except that methods in subclasses can also reference them.

    > Both private and protected members, though, are inaccessible from client code.


  Unlike attributes such as the return type, the "access specifier" inside the
  class declaration holds until replaced by a different specifier.

    Thus, each specifier usually appears only once, with the members grouped together by access.

      > This leads programmers to refer to “the public section” or “the private
      section” of a class, as in, “We should put this method in the private section.”



### Speaking of "struct"
You should know that in C++, struct and class denote nearly the same thing.

The only difference between the two involves members (data or methods)
declared before the first access specifier.

  In a struct, these members would be public,
  while in a class, they would be private.


Good programmers, though, use the two structures in different ways.

  Most programmers reserve struct for simpler structures,
  either those with no data members beyond constructors or those intended
  for use as parameters to methods of a larger class.


*/



#include <iostream>
#include <string>

using namespace std;



class sample
{

public:
  sample();        // default constructor
  sample(int num); // second constructor

  int doesSomething(double param); // method

private:
  int intData; // data member

};


sample::sample()
{
}

sample::sample(int aNum)
{
}

int sample::doesSomething(double aParam)
{
  return 0;
}



int main()
{
  cout << "Class Fundamentals - Theory." << endl;


  // Test
  sample object1;
  sample object2(15);



  cout << endl;
  return 0;
}
