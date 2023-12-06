#include <iostream>

using namespace std;

/*
Esercizio 3 - Lampadina
===================
"Creare le classi Lampadina e LampadinaColorata in relazione attraverso il vincolo di ereditarietà. 
Entrambe possono essere spente o accese. Quella colorata può anche gestire la caratteristica del colore, 
con valori come "giallo", "rosso", ecc., e la luminosità, espressa con valori da 1 a 10."

*/

class Lampadina {
private:
	bool accesa;
public:
	Lampadina() : accesa(false) {}
	void accendi() {
		accesa = true;
	}
	void spegni() {
		accesa = false;
	}
	bool isAccesa() {
		return accesa;
	}
};

class LampadinaColorata : public Lampadina{
private:
	string colore;
	int luminosita;
public:
	LampadinaColorata() : Lampadina(), colore("bianco"), luminosita(0) {}
	void setLuminosita(int newLuminosita) {
		if(!isAccesa()){
			cout << "La lampadina e' spenta" << endl;
			return;
		}
		if(newLuminosita <= 0 || newLuminosita > 10) {
			cout << "La luminosita' deve avere un valore compreso tra 1 e 10 inclusi'" << endl;
			return;
		}
		luminosita = luminosita;
	}
	void setColore(string newColore) {
		if(!isAccesa()){
			cout << "La lampadina e' spenta" << endl;
			return;
		}
		colore = newColore;
	}
};

int main()
{

	return 0;
}