//2014.01.17 Gustaf - CTG.


#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;


/*
PROBLEMA: Generar la siguiente secuencia.

1
2
3
4
3
2
1


*/

int main()
{
	//EVOLUCIÓN por experimentación para llegar al resultado esperado.
    for (int row = 1;  row <= 7; row++) {
    	cout << 8 - row << "\n";
	}

	cout << "\n";

    for (int row = 1;  row <= 7; row++) {
    	cout << 4 - row << "\n";
	}

	cout << "\n";


    for (int row = 1;  row <= 7; row++) {
    	cout << abs(4 - row) << "\n";
	}

	cout << "\n";

    for (int row = 1;  row <= 7; row++) {
    	cout << 4 - ( abs(4 - row) ) << "\n";
	}

	cout << "\n";


	//Generalización, funciona "raro" con números pares.
  //Secuencia que incrementa y luego a la mitad desciende.
	int show = 13; //filas a mostrar, deben ser impares.
	int half = ceil(show/2.0);
	// cout << half;
    for (int row = 1;  row <= show; row++) {
    	cout << half - ( abs(half - row) ) << "\n";
	}


	cout << "\n";


    return 0;
}
