//2014.02.06 - 2014.02.07 Gustaf - CTG.


/*


=== PLAN ===

OK - Convert binary to hexadecimal.
   OK - Group the input in groups of four digits.
   TO DO - Complete with leading zeros if necessary.
   OK - Map the equivalent binary group to its hexadecimal char.
   OK- Problem with grouping.

*/


#include <iostream>
#include <string>

using namespace std;



string binToHexa (string binaryGroup)
{
  if (binaryGroup == "0000")
  {
    return "0";
  }
  else if (binaryGroup == "0001")
  {
    return "1";
  }
  else if (binaryGroup == "0010")
  {
    return "2";
  }
  else if (binaryGroup == "0011")
  {
    return "3";
  }
  else if (binaryGroup == "0100")
  {
    return "4";
  }
  else if (binaryGroup == "0101")
  {
    return "5";
  }
  else if (binaryGroup == "0110")
  {
    return "6";
  }
  else if (binaryGroup == "0111")
  {
    return "7";
  }
  else if (binaryGroup == "1000")
  {
    return "8";
  }
  else if (binaryGroup == "1001")
  {
    return "9";
  }
  else if (binaryGroup == "1010")
  {
    return "A";
  }
  else if (binaryGroup == "1011")
  {
    return "B";
  }
  else if (binaryGroup == "1100")
  {
    return "C";
  }
  else if (binaryGroup == "1101")
  {
    return "D";
  }
  else if (binaryGroup == "1110")
  {
    return "E";
  }
  else if (binaryGroup == "1111")
  {
    return "F";
  }
  else 
  {
    return "@"; /*ERROR INDICATION*/
  }
}



int main()
{
  cout << "CONVERT binary to hexadecimal. \n";
  cout << "Enter an binary number of any length (JUST GROUPS OF 4 DIGITS!!): \n";

  string binaryGroup = "";
  string binaryOutput = "";
  string hexaOutput = "  ";
  int index = 1;

  char digitChar = cin.get();
  while (digitChar != 10)   //Check for the EOL key.
  {
    /*Grouping and output*/
    binaryGroup = binaryGroup + digitChar;

    digitChar = cin.get();

    index++;
    if (index == 5)
    {
      binaryOutput = binaryOutput + binaryGroup + ":";
      hexaOutput = hexaOutput+ binToHexa(binaryGroup) + "    " ;

      binaryGroup = "";
      index = 1;
    }

  }


  cout << binaryOutput << "\n";
  cout << hexaOutput << "\n";
  return 0;
}
