#include <iostream>

using namespace std;

/*LAMPADINA / LAMPADINA REGOLABILE / LAMPADINA REGOLABILE RGB (EREDITARIETA’)
Creare una classe lampadina che memorizza la potenza di una lampadina e se è accesa o spenta;
creare successivamente una classe lampadina regolabile che permette di creare lampadine in cui
la potenza della lampadina è regolabile in modo lineare tra 1 (minima potenza) e 10 (massima potenza);
creare infine una lampadina regolabile RGB che è una lampadina che può emettere luce colorata gestibile
in base alle quantità di rosso, verde e blu scelte e che possono variare per ogni colore tra 0 e 10.
*/

class Lampadina {
protected:
	bool accesa;
	int intensita;
public:
	Lampadina() : accesa(false), intensita(10) {}
	void interruttore() {
		accesa = !accesa;
	}
};

class LampadinaRegolabile : public Lampadina{
public:
	LampadinaRegolabile() : Lampadina() {}
	void impostaIntensita(int newIntensita) {
		if(newIntensita > 10) {
			cout << "La lampadina e' stata impostata alla  massima potenza(10)" << endl;
			intensita = 10;
		}
		else if(newIntensita < 1) {
			cout << "La lampadina e' stata impostata alla  minima potenza(1)" << endl;
			intensita = 1;
		}
		else {
			intensita = newIntensita;
		}
	}
};

class LampadinaRegolabileRGB : LampadinaRegolabile{
protected:
	int R, G, B;
	void impostaRed(int newR) {
		if(newR > 10) {
			R = 10;
		}
		else if(newR < 0) {
			R = 0;
		}
		else {
			R = newR;
		}
	}
	void impostaGreen(int newG) {
		if(newG > 10) {
			G = 10;
		}
		else if(newG < 0) {
			G = 0;
		}
		else {
			G = newG;
		}
	}
	void impostaBlue(int newB) {
		if(newB > 10) {
			B = 10;
		}
		else if(newB < 0) {
			B = 0;
		}
		else {
			B = newB;
		}
	}
public:
	LampadinaRegolabileRGB() : LampadinaRegolabile(), R(10), G(10), B(10) {}
	void impostaColore(int newR, int newG, int newB) {
		impostaRed(newR);
		impostaGreen(newG);
		impostaBlue(newB);
	}
};

int main() {

	return 0;
}