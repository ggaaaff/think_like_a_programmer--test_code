//2014.01.28 - 2014.01.29 - 2014.01.30 Gustaf - CTG.


/* INFORMATION

Excel
http://actualicese.com/modelos-y-formatos/excel-calculo-del-digito-de-verificacion-de-nits-luis-sabogal/

PDF with the theory.
http://www.gerencie.com/explicacion-sobre-el-procedimiento-para-calcular-el-digito-de-verificacion.html



EXAMPLE
Cada dígito del NIT 860,324,218 se multiplica por un número primo de acuerdo a la posición 
que ocupe ese dígito dentro del NIT, así:

(8 *41) + (6 *37) + (0 *29)  + (3 *23) + (2 *19) + (4 *17)  + (2 *13) + (1 *7) + (8 *3) = 782
782 mod 11 = 1

NOTA: Finalmente si este número es igual a uno (1) o cero (0), el dígito de verificación DV es el
mismo valor; de lo contrario el DV es igual a once (11) menos el obtenido como resultado.

860,324,218-1
8603242181



==========================================
PLAN

OK - Investigate the NIT system.
OK - Make an example.

 - Divide the problem that CHECK a NIT.
   - I guess it involves all the 10 digit and then: SUM module 11  = 0
   - I am not sure of the exact formula, so I've postponed.



OK - Divide the problem that CALCULATE the check digit of a NIT.
  OK - Based on the code for the 13-digit ISBN.
  OK - Capture the first 9 digits.
  OK - Sum all digits. 
  OK - Multiply each one and sum all.
  OK - The result of sum module 11.
  OK - If the result is different from 1 or 0: 11 minus result is the correct check digit.
  OK - Display the check digit 


*/


#include <iostream>
#include <string>

using namespace std;
// using std::cin;
// using std::cout;





bool INCOMPLETE__is_valid_nit(int digits[10])
{
  int primes[10] = {41,37,29,23,19,17,13,7,3,1};
  // cout << primes[0] << primes[9];
  
  int i;
  int check = 0;
  for (i = 0; i < 10; i++) {
    check = check + (digits[i] * primes[i]);

    // cout << "SUM: " << "  " << digits[i] << "  " << primes[i] << " : "  << check << "\n";

  }

  int sum9 = (check -(digits[9] * primes[9]) );
  cout << "SUM  9 digits: " << sum9 << " sum nodule 11: " << (sum9 % 11) << "\n";

  cout << "SUM 10 digits: " << check << " sum nodule 11: " << (check % 11) << "\n";

  return (check % 11) == 0;  /*THIS IS NOT THE RIGHT FORMULA FOR THE CHECK.*/
}




int main()
{
  cout << "Calculate the digit check of a NIT. \n";
  // cout << "Check a NIT. POSTPONED \n";

  cout << "Introduce a 10 digit number (no symbols).  \n";

  char digitChar;
  int index = 1;
  int sum = 0;
  int numProduct = 0;
  int result = -1;
  int checkDigitTyped = -1;
  int primes[9] = {41,37,29,23,19,17,13,7,3};

  index = 1;
  digitChar = cin.get();
  while (digitChar != 10)  /*check EOL*/
  {
    
    if ( index <= 9 ) /*Exclude from the sum the check digit*/
    {
      numProduct = primes[index-1] * (digitChar - '0');

      sum = sum + numProduct;
    }

    digitChar = cin.get();
    index++;

    if (index == 10) /*Get the 10th digit typed*/
    {
      checkDigitTyped = (digitChar - '0');
    }
  }

  cout << "\n";
  // cout << "SUM: " << (sum) << "\n";

  if ((index -1) != 10) {
    cout << "ERROR introducing the exact number of digits. \n";
    cout << "Digits: " << (index -1) << "\n";
  } else {
    result = (sum % 11); /*Get the preliminar check digit*/
    if (result > 1) { 
      result = (11 - result); /*Transform if different to 1 or 0*/
    }
    cout << "CHECK DIGIT, TYPED      : " << checkDigitTyped << "\n";
    cout << "CHECK DIGIT, CALCULATED : " << result << "\n";

    if (result == checkDigitTyped) {
      cout << "The NIT is correct. \n";
    } else {
      cout << "The NIT is not correct. \n";
    }
  }

  cout << "\n";
  return 0;}

