//2014.07.20 Gustaf-37 - CTG.


/* PROBLEM : CLASS ROSTER

Design a class or set of classes for use in a program that maintains a class roster.

  For each student, store:
    the student’s name, ID, and final grade score in the range 0–100.

The program will allow student records to be added or removed;
display the record of a particular student, identified by ID, with the grade
  displayed as a number and as a letter;
and display the average score for the class.


  The appropriate letter grade for a particular score is shown in Table 5-1.

  Score Range   Letter Grade
     93–100          A
     90–92           A–
     87–89           B+
     83–86           B
     80–82           B–
     77–79           C+
     73–76           C
     70–72           C–
     67–69           D+
     60–66           D
     0–59            F



=== PLAN ===

OK - Basic class framework.
-

*/



#include <iostream>
#include <string>

using namespace std;



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




int main()
{
  cout << "Class roster." << endl;



  cout << endl;
  return 0;
}
