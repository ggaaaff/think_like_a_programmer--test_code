//2014.03.21 Gustaf - CTG.


/* P R O B L E M : T R A C K I N G  A N  U N K N O W N  Q U A N T I T Y  O F  S T U D E N T  R E C O R D S

In this problem, you will write functions to store and manipulate a collection of student records.
  A student record contains a student number and a grade, both integers.


The following functions are to be implemented:

  addRecord
  This function takes a pointer to a collection of student records (a student
  number and a grade), and it adds a new record with this data to the collection.

  averageRecord
  This function takes a pointer to a collection of student records
  and returns the simple average of student grades in the collection as a double.


The collection can be of any size.
The addRecord operation is expected to be called frequently,
so it must be implemented efficiently.




=== PLAN ===

-
-

*/



#include <iostream>

using namespace std;


struct listNode
{
  int studentNum;
  int grade;

  // To make a linked list, you need a struct that contains a pointer to the same struct.
  listNode *next;
};


typedef listNode *studentCollection;
  // For readability we are using the studentCollection type 
  // only for variables that will refer to the whole list structure.



int main()
{
  cout << "Hello world - Linux Mint." << endl;

  // the -> notation is used to indicate the field of a pointed-to struct (or class).


  // ---
  studentCollection sc;

  // Creating the nodes
  listNode *node1 = new listNode;
  node1->studentNum = 1001; node1->grade = 78;

  listNode *node2 = new listNode;
  node2->studentNum = 1012; node2->grade = 93;

  listNode *node3 = new listNode;
  node3->studentNum = 1076; node3->grade = 85;

  // Creating the linked list
  sc = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;
 
  node1 = node2 = node3 = NULL; // NOTICE: to clean things up and avoid potential cross-linking problems.




  // ---


  cout << endl;
  return 0;
}
