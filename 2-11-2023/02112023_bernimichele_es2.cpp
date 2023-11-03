#include <iostream>
#include <string>

using namespace std;

/*2. Esercizio sulla classe Fucile in C++:

Crea una classe `Fucile` avanzata che può sparare diversi tipi di proiettili, come proiettili perforanti, esplosivi o traccianti. Ogni tipo di proiettile ha caratteristiche diverse. Implementa i seguenti metodi:

- `Sparo(int tipoProiettile)`: fa sparare il fucile usando il tipo specificato di proiettile.
- `RicaricaTipoProiettile(int tipoProiettile)`: ricarica il fucile con il tipo specificato di proiettile.
- `ModificaModalitaSparo(bool automatica)`: permette di cambiare la modalità di sparo tra automatica e semiautomatica per tutti i tipi di proiettili.
- `StatoFucile()`: restituisce lo stato del fucile, indicando il numero di proiettili rimanenti per ciascun tipo.
*/

class Fucile{
private:
	int dimCaricatore;
	pair<int, int> caricatore;
	bool automatico;
public:
	Fucile(int dimCaricatore) {
		this->dimCaricatore = dimCaricatore;
		automatico = false;
		caricatore.first = 0;
		caricatore.second = 0;
	}
	void ricarica(int tipoProiettile) {
		caricatore.first = dimCaricatore;
		caricatore.second = tipoProiettile;
	}
	void modificaModalitaSparo() {
		automatico = !automatico;
		cout << "Modalita di sparo impostata su " << (automatico ? "automatico" : "semiautomatico") << endl;
	}
	void spara() {
		if (caricatore.first <= 0) {
			cout << "Fucile scarico" << endl;
			return;
		}
		if (!automatico) {
			cout << "Bang!" << caricatore.second << endl;
			caricatore.first--;
		}
		else {
			for(;caricatore.first > 0; caricatore.first--) {
				cout << "Bang!" << caricatore.second << endl;
			}		
		}
	}
	pair<int, int> statoFucile() {
		return caricatore;
	}
};

int main()
{
	Fucile f1(30);
	
	f1.ricarica(1);
	f1.modificaModalitaSparo();
	cout << "Colpi nel caricatore: " << f1.statoFucile().first << endl << "Tipo di proiettile: " <<  f1.statoFucile().second << endl;
	f1.spara();
	cout << "Colpi nel caricatore: " << f1.statoFucile().first << endl << "Tipo di proiettile: " <<  f1.statoFucile().second << endl;
	
	return 0;
}