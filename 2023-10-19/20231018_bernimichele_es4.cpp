#include <iostream>

using namespace std;

/*4. Esercizio sulla classe Calcolatrice in C++:

Creare una classe `Calcolatrice` che possa eseguire operazioni matematiche di base. Questa classe dovrebbe avere i seguenti metodi:

- `Somma(int a, int b)`: restituisce la somma di due numeri interi.
- `Sottrazione(int a, int b)`: restituisce la differenza tra due numeri interi.
- `Moltiplicazione(int a, int b)`: restituisce il prodotto di due numeri interi.
- `Divisione(float a, float b)`: restituisce il risultato della divisione tra due numeri in virgola mobile. Se il secondo numero è zero, dovrebbe stampare un messaggio di errore anziché eseguire la divisione.
*/

class Calcolatrice {
public:
	int somma(int a, int b) {
		return a + b;
	}
	int sottrazione(int a, int b) {
		return a - b;
	}
	int moltiplicazione(int a, int b) {
		return a * b;
	}
	float divisione(float a, float b) {
		if (b != 0) {
			return a / b;
		}
		else {
			cout << "E' impossibile dividere per 0\n";
		}
	}
};

int main()
{
	Calcolatrice c1;
	cout << c1.somma(23, 12) << endl << c1.sottrazione(12, 6) << endl << c1.moltiplicazione(3, 4) << endl << c1.divisione(3, 0) << c1.divisione(12, 4);


	return 0;
}