//2014.02.15 Gustaf - CTG.


/*
For example, consider the problem of finding the highest of a set of student grades.
Suppose that instead of an array of int, we have an array of data
structures, each representing a student’s record.


*/



#include <iostream>
#include <string>

using namespace std;



int main()
{
  cout << "Finding the highest of a set of student grades. \n";

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

  int highest = studentArray[0].grade;
  for (int i = 1; i < ARRAY_SIZE; i++)
  {
    if (studentArray[i].grade > highest)
      highest = studentArray[i].grade;
  }


  cout << highest << " the highest grade.\n";
  return 0;
}
