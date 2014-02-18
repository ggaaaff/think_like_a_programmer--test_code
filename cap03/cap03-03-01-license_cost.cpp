//2014.02.14 Gustaf - CTG.

/*
Suppose you are writing a program
to compute the cost of a business license in a state where the license cost
varies as the gross sales figures of the business vary.


Table 3-1: Business License Costs

Business category | Sales threshold | License cost
        I                 $0              $25
        II                $50,000         $200
        III               $150,000        $1,000
        IV                $500,000        $5,000


*/



#include <iostream>
#include <string>

using namespace std;



int main()
{
  cout << "License cost - Enter the Gross Sales. \n";

  int category = 0;
  double cost = 0.0;

  int grossSales = 0;
  cin >> grossSales;

  const int NUM_CATEGORIES = 4;
  const double categoryThresholds[NUM_CATEGORIES ] = {0.0, 50000.0, 150000.0, 500000.0};
  const double licenseCost[NUM_CATEGORIES ] =  {25.0, 200.0, 1000.0, 5000.0};

  category = 0;
  while ( category < NUM_CATEGORIES
          && categoryThresholds[category] <= grossSales )
  {
    category++;
  }
  cost = licenseCost[category - 1];

  cout << cost << " the cost of the license.\n";
  return 0;
}
