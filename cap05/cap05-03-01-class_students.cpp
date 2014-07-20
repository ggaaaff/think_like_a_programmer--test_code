//2014.07.20 Gustaf-37 - CTG.


/* PROBLEM  :

T R A C K I N G   A N   U N K N O W N  Q U A N T I T Y   O F   S TU D E N T   R E C O R D S

In this problem, you will write a class with methods to store and manipulate a collection
of student records. A student record contains a student number and a grade,
both integers, and a string for the student name.


The following functions are to be implemented:

  addRecord This method takes a student number, name, and grade and adds a
  new record with this data to the collection.

  recordWithNumber This function takes a student number and retrieves the record
  with that student number from the collection.

  removeRecord This function takes a student number and removes the record with
  that student number from the collection.


The collection can be of any size.

The addRecord operation is expected to be called frequently,
so it must be implemented efficiently.



=== PLAN ===

-
-

*/



#include <iostream>
#include <string>

using namespace std;


struct studentRecord
{
  int studentNum;
  string name;
  int grade;
};



class studentCollection
{

private:
  struct studentNode
  {
    studentRecord studentData;
    studentNode *next;
  };

public:
  studentCollection();

  void addRecord(studentRecord newStudent);
  void removeRecord(int idNum);
  studentRecord recordWithNumber(int idNum);

private:
  typedef studentNode *studentList;
  studentList _listHead;
};


int main()
{
  cout << "Hello world - Linux Mint 15." << endl;

  cout << endl;
  return 0;
}
