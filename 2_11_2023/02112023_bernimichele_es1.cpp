#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

/*1. Esercizio sulla classe LampadinaLed in C:

Crea una classe `LampadinaLed` che può essere controllata da più interruttori in posizioni diverse, e può essere collegata a un sensore di movimento. La lampadina dovrebbe essere in grado di regolare la luminosità in base alla posizione degli interruttori e accendersi automaticamente quando viene rilevato un movimento. Implementa i seguenti metodi:

- `AccendiDaInterruttore(int numeroInterruttore)`: accende la lampadina dal determinato interruttore.
- `SpegniDaInterruttore(int numeroInterruttore)`: spegne la lampadina dal determinato interruttore.
- `RegolaLuminositaDaInterruttore(int numeroInterruttore, int luminosita)`: regola la luminosità della lampadina da un interruttore specifico.
- `AttivaRilevamentoMovimento()`: attiva il sensore di movimento per accendere automaticamente la lampadina quando viene rilevato un movimento.
- `DisattivaRilevamentoMovimento()`: disattiva il sensore di movimento.*/

#define MAX_LUMINOSITA 100

class LampadinaLed {
private:
	bool sensore;
	short stato;
	vector<short> interruttori;
	POINT cursorPos;
	void sensorLoop () {
		long oldX = 0, oldY = 0;
		while (sensore) {
			GetCursorPos(&cursorPos);
			if (cursorPos.x == oldX && cursorPos.y == oldY) {
				stato = 0;
			}
			else {
				stato = MAX_LUMINOSITA;
			}
			oldX = cursorPos.x;
			oldY = cursorPos.y;
			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}
public:
	LampadinaLed() : sensore(false), stato(0) {};
	void aggiungiInterruttore() {
		interruttori.push_back(MAX_LUMINOSITA);
		cout << "Creato l'interruttore numero " << interruttori.size() << endl;
	}
	void accendiDaInterruttore(int numeroInterruttore) {
		if (numeroInterruttore > interruttori.size()) {
			cerr << "Impossibile accendere dall'interruttore richiesto perche' non esiste" << endl;
			return;
		}
		int indexEffettivo = numeroInterruttore - 1;
		stato = interruttori[indexEffettivo];
	}
	void spegniDaInterruttore(int numeroInterruttore) {
		if (numeroInterruttore > interruttori.size()) {
			cerr << "Impossibile spegnere dall'interruttore richiesto perche' non esiste" << endl;
			return;
		}
		stato = 0;
	}
	void regolaLuminositaDaInterruttore(int numeroInterruttore, short luminosita) {
		if (numeroInterruttore > interruttori.size()) {
			cerr << "Impossibile modificare la luminosita' dell'interruttore richiesto perche' non esiste" << endl;
			return;
		}
		int indexEffettivo = numeroInterruttore - 1;
		interruttori[indexEffettivo] = luminosita;
	}
	short getStato() {
		return stato;
	}
	void attivaRilevamentoMovimento() {
		sensore = true;
		thread t(&LampadinaLed::sensorLoop, this);
		t.detach();
	}
	void disattivaRilevamentoMovimento() {
		sensore = false;
	}
};


int main()
{
	LampadinaLed l1;
	
	l1.aggiungiInterruttore();
	l1.aggiungiInterruttore();
	l1.accendiDaInterruttore(3);
	cout << "stato: " << l1.getStato() << endl;
	l1.accendiDaInterruttore(2);
	cout << "stato: " << l1.getStato() << endl;
	l1.spegniDaInterruttore(2);
	cout << "stato: " << l1.getStato() << endl;
	l1.regolaLuminositaDaInterruttore(2, 50);
	cout << "stato: " << l1.getStato() << endl;
	l1.accendiDaInterruttore(2);
	cout << "stato: " << l1.getStato() << endl;
	l1.attivaRilevamentoMovimento();
	for(int i = 0; i < 200; i++) {
		cout << "stato: " << l1.getStato() << endl;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	l1.disattivaRilevamentoMovimento();
	
	return 0;
}