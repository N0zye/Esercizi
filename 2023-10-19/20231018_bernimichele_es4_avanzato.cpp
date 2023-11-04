#include <iostream>

using namespace std;

/*4. Esercizio sulla classe Calcolatrice in C++:

Creare una classe `Calcolatrice` che possa eseguire operazioni matematiche di base. Questa classe dovrebbe avere i seguenti metodi:

- `Somma(int a, int b)`: restituisce la somma di due numeri interi.
- `Sottrazione(int a, int b)`: restituisce la differenza tra due numeri interi.
- `Moltiplicazione(int a, int b)`: restituisce il prodotto di due numeri interi.
- `Divisione(float a, float b)`: restituisce il risultato della divisione tra due numeri in virgola mobile. Se il secondo numero è zero, dovrebbe stampare un messaggio di errore anziché eseguire la divisione.
- `RadiceQuadrata(float numero)`: restituisce la radice quadrata di un numero in virgola mobile.
- `Potenza(float base, float esponente)`: calcola la base elevata all'esponente.
- `Fattoriale(int numero)`: calcola il fattoriale di un numero intero positivo.
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
	float radiceQuadrata(float numero) {
		return sqrt(numero);
	}
	float potenza(float base, int esponente) {
		if (esponente == 0) {
			return 1;
		}
		else {
			for (int i = 0; i < esponente; i++) {
				base *= base;
			}
			return base;
		}
	}
	int fattoriale(int numero) {
		for (int i = 0; i < numero; i++) {
			numero *= numero - i;
		}
	}

};

int main()
{
	return 0;
}