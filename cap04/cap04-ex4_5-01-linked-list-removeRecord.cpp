//2014.04.17 Gustaf - CTG.


/* EXERCISE 4-5 :

Write a function removeRecord that takes a pointer to a studentCollection and a
student number and that removes the record with that student number from the collection.


=== PLAN ===

OK - function output the list of students.
OK - function add Record.
OK - function remove Record.

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



void outputListStudent(studentCollection &sc)
{
  cout << endl << "Listado de estudiantes (Student number - grade) : " << endl;

  listNode *loopPtr = sc;
  while (loopPtr != NULL)
  {
    cout << "(" << loopPtr -> studentNum << " - " << loopPtr -> grade << ")" << endl;
    loopPtr = loopPtr -> next;
  }
}


void addRecord(studentCollection &sc, int stuNum, int gr)
{
  // After the new node is created, it is linked into the list at the beginning.

  // New node
  listNode *newNode = new listNode;
  newNode -> studentNum = stuNum;
  newNode -> grade = gr;


  newNode -> next = sc; // linked at the beginning of the list
  sc = newNode; // new head pointer
}


void removeRecord(studentCollection &sc, int stuNum)
{
  listNode *beforeNode = NULL;
  listNode *remNode    = NULL;


  listNode *loopPtr = sc;
  while (loopPtr != NULL)
  {

    if (stuNum == loopPtr -> studentNum)
    {
      remNode = loopPtr;

      if (beforeNode == NULL)
      {
        sc = sc -> next; // New head
      }
      else
      {
        beforeNode -> next = loopPtr -> next; // New link
      }

    }

    beforeNode = loopPtr;
    loopPtr    = loopPtr -> next;
  }

  // Free memory
  cout << endl << "Student removed: " << remNode -> studentNum << endl;
  delete[] remNode;
}



int main()
{
  cout << "Linked list - Remove Record." << endl;


  // ---
  studentCollection sc = NULL; // First node or head pointer.
  addRecord(sc, 4004, 78);
  addRecord(sc, 3003, 45);
  addRecord(sc, 2002, 23);
  addRecord(sc, 1001, 60);
  outputListStudent(sc);

  removeRecord(sc, 4004);
  outputListStudent(sc);

  removeRecord(sc, 1001);
  outputListStudent(sc);


  cout << endl;
  return 0;
}
