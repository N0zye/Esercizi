/*
NOTA: Nella consegna indicare i componenti del grupo.
1. Merendine
===========

la macchinetta presenta un menu.

L'avventore inserisce i soldi
Il cliente fa la selezione

la macchinetta eroga la merendina (90%)
e fornisce il resto.

Nell'altro 10% si verifica un malfunzionamento e restituisce tutti i soldi scusandosi


2. Caffè
=======

la macchinetta presenta un menu.

L'avventore inserisce i soldi
Il cliente fa la selezione

la macchinetta eroga la bevanda (95%)
e fornisce il resto.

Nell'altro 5% si verifica un malfunzionamento e restituisce tutti i soldi scusandosi
*/

#include <iostream>
#include <random>
#include <stdexcept>
#include <map>

using namespace std;

class MacchinettaMerendine {
private:
	map<string, float> menu;
	float soldiInseriti;

public:
	MacchinettaMerendine(map<string, float> menu) : menu(menu), soldiInseriti(0.0) {}
	void mostraMenu() {
		for(map<string, float>::iterator it = menu.begin(); it != menu.end(); it++) {
			cout << it->first << " prezzo: " << it->second << endl;
		}
	}
	void inserisciSoldi(float soldi) {
		soldiInseriti += soldi;
	}
	float seleziona(string selezione) {
		srand(time(NULL));
		if(rand() % 10 == 7) {   //malfunzionamento
			cout << "Errore nel sistema, contatta l'assistenza, ecco il tuo resto" << endl;
			float temp = soldiInseriti;
			soldiInseriti = 0;
			return temp;
		}
		try {
			float prezzoDellaSelezione = menu.at(selezione);
			if(prezzoDellaSelezione > soldiInseriti) {
				cout << "Credito insufficiente" << endl;
				return 0;
			}
			cout << "ecco a te la tua merendina" << endl;
			return soldiInseriti-prezzoDellaSelezione;
		}
		catch (out_of_range &e) {
			cout << "La merendina richiesta non e' nel menu" << endl;
			return 0;
		}
	}
};

class MacchinettaCaffe {
private:
	map<string, float> menu;
	float soldiInseriti;

public:
	MacchinettaCaffe(map<string, float> menu) : menu(menu), soldiInseriti(0.0) {}
	void mostraMenu() {
		for(map<string, float>::iterator it = menu.begin(); it != menu.end(); it++) {
			cout << it->first << " prezzo: " << it->second << endl;
		}
	}
	void inserisciSoldi(float soldi) {
		soldiInseriti += soldi;
	}
	float seleziona(string selezione) {
		srand(time(NULL));
		if(rand() % 20 == 7) {   //malfunzionamento
			cout << "Errore nel sistema, contatta l'assistenza, ecco il tuo resto" << endl;
			float temp = soldiInseriti;
			soldiInseriti = 0;
			return temp;
		}
		try {
			float prezzoDellaSelezione = menu.at(selezione);
			if(prezzoDellaSelezione > soldiInseriti) {
				cout << "Credito insufficiente" << endl;
				return 0;
			}
			cout << "ecco a te la tua bevanda" << endl;
			return soldiInseriti-prezzoDellaSelezione;
		}
		catch (out_of_range &e) {
			cout << "La bevanda richiesta non e' nel menu" << endl;
			return 0;
		}
	}
};


int main() {


	return 0;
}