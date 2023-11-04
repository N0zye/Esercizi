#include <iostream>

using namespace std;

/*1. Esercizio sulla classe LampadinaLed in C++:

Crea una classe `LampadinaLed` che possieda una caratteristica unica : può cambiare il suo stato tra acceso e spento non solo attraverso un semplice interruttore, ma anche in base a condizioni esterne come l'intensità di luce circostante. La classe dovrebbe avere i seguenti metodi:

- `Accendi()`: accende la lampadina se l'intensità di luce circostante è inferiore a una soglia specifica.
- `Spegni()`: spegne la lampadina se l'intensità di luce circostante è superiore alla soglia.
- `ModificaSoglia(int nuovaSoglia)`: permette di cambiare la soglia di luce necessaria per accendere o spegnere la lampadina.
- `Stato()`: restituisce lo stato attuale della lampadina(acceso o spento).*/

int intensitaLuce = 100;

class LampadinaLed {
private:
	bool acceso;
	int soglia;
public:
	LampadinaLed(int sogliaIniziale) {
		acceso = false;
		soglia = sogliaIniziale;
	}
	void accendi() {
		if (intensitaLuce < soglia) {
			acceso = true;
		}
		else {
			cout << "Errore impossibile accendere la luce, l'intensita' della luce circostante e' superiore alla soglia specificata\n";
		}
	}
	void spegni() {
		if (intensitaLuce > soglia) {
			acceso = false;
		}
		else {
			cout << "Errore impossibile spegnere la luce, l'intensita' della luce circostante e' inferiore alla soglia specificata\n";
		}
	}
	void modificaSoglia(int nuovaSoglia) {
		soglia = nuovaSoglia;
	}
	string stato() {
		return acceso ? "Si" : "No";
	}
};

int main()
{
	LampadinaLed l1(50);
	cout << "Accesa: " << l1.stato() << endl;
	l1.accendi();
	cout << "Accesa: " << l1.stato() << endl;
	l1.modificaSoglia(150);
	cout << "Accesa: " << l1.stato() << endl;
	l1.accendi();
	cout << "Accesa: " << l1.stato() << endl;
	l1.spegni();
	cout << "Accesa: " << l1.stato() << endl;

	return 0;
}