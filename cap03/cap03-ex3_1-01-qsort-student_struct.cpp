//2014.02.18 Gustaf - CTG.


/* EXERCISE 3-1:
Are you disappointed we didn’t do more with sorting? I’m here to help. To
make sure you are comfortable with qsort, 

write code that uses the function to sort an array of our student struct. 
First have it sort by grade, and then try it again using the student ID.



=== PLAN ===

HMM - I felt a little stuck because I was thinking that the qsort function could adjust 
the things inside the struct magically. 

Then I changed my approach:
  OK - Extract the data in one array.
  OK - Sort the newly created array.

*/



#include <iostream>
#include <cstdlib>

using namespace std;



/*

int compareFunc(const void *voidA, const void *voidB)
{
  int *intA = (int *)(voidA);
  int *intB = (int *)(voidB);
  return *intA - *intB;
}
*/


int compareFunc (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );  //This is equivalent to the above code.
}


int main()
{
  cout << "Sorting the struct by grade and by student ID." << endl << endl;


  struct student
  {
    int grade;
    int studentID;
    string name;
  };

  const int ARRAY_SIZE = 10;
  student studentArray[ARRAY_SIZE] =
  {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"}
  };


  //-- Creating new array for grades.
  int grades[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    grades[i] = studentArray[i].grade;
  }

  //Sort and output grades.
  qsort(grades, ARRAY_SIZE, sizeof(int), compareFunc);

  cout << "Sort grades." << endl;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << grades[i] << " ";
  }
  cout << endl << endl;


  //-- Creating new array for student ID.
  int studentsId[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    studentsId[i] = studentArray[i].studentID;
  }

  //Sort and output student ID.
  qsort(studentsId, ARRAY_SIZE, sizeof(int), compareFunc);

  cout << "Sort students ID." << endl;
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    cout << studentsId[i] << " ";
  }
  cout << endl;



  cout << endl;
  return 0;
}
