//2014.07.20 - 2014.07.21 - 2014.07.22 Gustaf-37 - CTG.



/* PROBLEM  :

T R A C K I N G   A N   U N K N O W N   Q U A N T I T Y   O F   S TU D E N T   R E C O R D S

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

OK - Reuse class studentRecord from code:
  /cap05-02-02-class_roster-support_methods.cpp

-



*/



#include <iostream>
#include <string>

using namespace std;



// -----------------------------------------------------------------------------

class studentRecord
{
public:
  studentRecord();
  studentRecord(int newGrade, int newID, string newName);

  int grade();
  void setGrade(int newGrade);

  int studentID();
  void setStudentID(int newID);

  string name();
  void setName(string newName);

  // Support Methods
  string letterGrade();

protected:
  bool isValidGrade(int grade);

private:
  int _grade;
  int _studentID;
  string _name;
};


// -- Public Methods --

studentRecord::studentRecord()
{
  // Values that indicate the object is not properly initialized.
  setGrade(0);
  setStudentID(-1); //Notice: invalid ID.
  setName("");
}

studentRecord::studentRecord(int newGrade, int newID, string newName)
{
  setGrade(newGrade);
  setStudentID(newID);
  setName(newName);
}


int studentRecord::grade()
{
  return _grade;
}

void studentRecord::setGrade(int newGrade)
{
  if (isValidGrade(newGrade))
  {
    _grade = newGrade;
  }
}


int studentRecord::studentID()
{
  return _studentID;
}

void studentRecord::setStudentID(int newID)
{
  _studentID = newID;
}


string studentRecord::name()
{
  return _name;
}

void studentRecord::setName(string newName)
{
  _name = newName;
}


string studentRecord::letterGrade()
{
  if (!isValidGrade(_grade))
    return "ERROR";

  const int NUMBER_CATEGORIES = 11;
  const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
  const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};

  int category = 0;
  while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
    category++;

  return GRADE_LETTER[category - 1];
}



// -- Protected Methods --

bool studentRecord::isValidGrade(int grade)
{
  if ((grade >= 0) && (grade <= 100))
    return true;
  else
    return false;
}




// -----------------------------------------------------------------------------

class studentCollection
{

private:
  struct studentNode
  {
    studentRecord studentData;
    studentNode *next;
  };

public:
  studentCollection();  // constructor
  ~studentCollection(); // destructor

  void addRecord(studentRecord newStudent);
  void removeRecord(int idNum);
  studentRecord recordWithNumber(int idNum);

private:
  typedef studentNode *studentList;
  studentList _listHead;

  void deleteList(studentList &listPtr);
};



studentCollection::studentCollection()
{
  _listHead = NULL; // initialization.
}


studentCollection::~studentCollection()
{
  deleteList(_listHead); // cleans memory.
}


void studentCollection::addRecord(studentRecord newStudent)
{
  studentNode *newNode   = new studentNode;
  newNode -> studentData = newStudent;

  // Link at the beginning
  newNode -> next = _listHead;
  _listHead = newNode;
}


studentRecord studentCollection::recordWithNumber(int idNum)
{
  /*
   WARNING: The function that calls this method is responsible for checking the
   studentRecord that comes back and making sure it’s not the dummy record
   before further processing.
  */

  studentNode *loopPtr = _listHead;
  while ( (loopPtr != NULL) && (loopPtr -> studentData.studentID() != idNum) )
  {
    loopPtr = loopPtr -> next;
  }

  if (loopPtr == NULL)
  {
    // If the list is empty or couldn't find the ID, then creates a fake record.
    studentRecord dummyRecord(-1, -1, "");
    return dummyRecord;
  }
  else
  {
    return loopPtr -> studentData;
  }

}


void studentCollection::removeRecord(int idNum)
{
  studentNode *trailing = NULL;

  // Finding the ID
  studentNode *loopPtr = _listHead;
  while (loopPtr != NULL && loopPtr -> studentData.studentID() != idNum)
  {
    trailing = loopPtr;
    loopPtr  = loopPtr -> next;
  }

  // list is empty or couldn't find the ID.
  if (loopPtr == NULL)
    return;

  // New link that "removes" the node.
  if (trailing == NULL)
  {
    _listHead = _listHead -> next;
  }
  else
  {
    trailing -> next = loopPtr -> next;
  }

  delete loopPtr; // Clean memory.
}


void studentCollection::deleteList(studentList &listPtr)
{
  while (listPtr != NULL)
  {
    studentNode *temp = listPtr;

    listPtr = listPtr -> next;
    delete temp;
  }
}



int main()
{
  cout << "Tracking students records (with a linked list wrapped out by a class)." << endl;


  // Test I
  studentCollection s;

  studentRecord stu3(84, 1152, "Sue");
  studentRecord stu2(75, 4875, "Ed");
  studentRecord stu1(98, 2938, "Todd");
  s.addRecord(stu3);
  s.addRecord(stu2);
  s.addRecord(stu1);

  s.removeRecord(4875);


  cout << endl;
  return 0;
}
