//2014.03.10 - 2014.03.11 Gustaf - CTG.


/* EXERCISE 3-8:
Write a program that processes an array of student objects and determines
the grade quartiles — that is, the grade one would need to score as well as or
 better than 25% of the students, 50% of the students, and 75% of the students.



==== INFORMATION ===
http://en.wikipedia.org/wiki/Quartile

In descriptive statistics, the quartiles of a ranked set of data values are the three points
that divide the data set into four equal groups, each group comprising a quarter of the data.

  The first quartile (Q1) is defined as the middle number between the smallest number and the median of the data set.
  The second quartile (Q2) is the median of the data.
  The third quartile (Q3) is the middle value between the median and the highest value of the data set.


  Two examples:
  http://en.wikipedia.org/wiki/Quantile#Examples



-------------------------------------------------
A crystal clear example:
http://www.vias.org/tmdatanaleng/cc_quartile.html


The calculation of the quartiles is sometimes not quite clear (especially if the number of observations of a sample
is not divisible by four). We therefore provide exact instructions how to calculate the quartiles.
Assuming a sample of N observations the quartiles are defined as follows
("round" stands for the rounding to the nearest integer) :

  1. quartile : the value of the sorted series of observations having the position x = round(0.25 * (N + 1))
  2. quartile (median) : if N is even, Q2 is the mean of the two values at the positions N / 2 and N / 2 + 1;
     if N is odd, Q2 is the value at the position (N + 1) / 2
  3. quartile: the value of the sorted series having the position x = round(0.75 * (N + 1))

  Remark on practical aspects: quartiles are usually calculated only for samples with more than 12 observations
  (a minimum of 20 observations would be even better).




-------------------------------------------------
A online Calculator:
http://www.hackmath.net/en/calculator/quartile-q1-q2-q3-calculation




=== PLAN ===

OK - Get information.
OK- Select a method (one out of three) to do the calculation.
  Selected the one from vias.org
- Calculate the quartiles.

*/



#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;



struct student
{
  string name;
  int studentID;
  int grade;
};

const int ARRAY_SIZE = 20;
student studentArray[ARRAY_SIZE] =
{
  { "student01" , 10001, 87 },
  { "student02" , 10002, 28 },
  { "student03" , 10003, 10 },
  { "student04" , 10004, 78 },
  { "student05" , 10005, 84 },
  { "student06" , 10006, 98 },
  { "student07" , 10007, 75 },
  { "student08" , 10008, 70 },
  { "student09" , 10009, 81 },
  { "student10" , 10010, 68 },
  { "student11" , 10011, 87 },
  { "student12" , 10012, 28 },
  { "student13" , 10013, 10 },
  { "student14" , 10014, 78 },
  { "student15" , 10015, 84 },
  { "student16" , 10016, 98 },
  { "student17" , 10017, 75 },
  { "student18" , 10018, 70 },
  { "student19" , 10019, 81 },
  { "student20" , 10020, 68 }
};

int compareFunc (const void *a, const void *b)
{
  return ( *(int *)a - * (int *)b );
} //-- function



int main()
{
  cout << "Process of students quartiles." << endl;


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





  cout << endl;
  return 0;
}
