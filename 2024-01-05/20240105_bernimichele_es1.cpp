#include <iostream>

using namespace std;

/*MATITA /MATITA CON GOMMINO (EREDITARIETA’)
Creare una classe Matita che serve per rappresentare delle matite e memorizzarne la lunghezza.
Creare una sottoclasse MatitaConGommino che serve per rappresentare delle matite con gommino,
la classe memorizza le caratteristiche delle matite e il numero cancellature rimaste a disposizione tramite
il gommino (tali matite partono con 10 possibilità di cancellature).
Creare le classi e provarle.*/

class Matita {
protected:
	float lunghezza;
public:
	Matita() : lunghezza(10.0) {}
	void scrivi(string text) {
		for (int i = 0; lunghezza > 0 && i < (int)text.length(); i++) {
			cout << text[i];
			lunghezza -= 0.1;
		}
		cout << endl;
		if(lunghezza <= 0) {
			cout << "E' finita la matita" << endl;
		}	
	}
};

class MatitaConGommino : public Matita{
protected:
	int cancellatureRimaste;
public:
	MatitaConGommino() : Matita(), cancellatureRimaste(10) {}
	void cancella() {
		if(cancellatureRimaste <= 0) {
			cout << "E' finita la gomma, impossibile cancellare" << endl;
			return;
		}
		system("cls");
	}
};

int main() {

	Matita m;
	MatitaConGommino mg;

	m.scrivi("Hello World!");
	mg.scrivi("Hello World!!");
	getchar();
	mg.cancella();

	return 0;
}