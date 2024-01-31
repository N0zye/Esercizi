#include <iostream>
#include <map>

using namespace std;

/*Modellare un carrello della spesa.

All'interno posso inserire prodotti di qualunque genere.

Voglio poter calcolare quanto spendo in totale e quanto pesa la spesa.

N.B. Almeno 5 classi diverse.*/

class Prodotto {
public:
	virtual double getPrezzoSingolo() = 0;
	virtual double getPesoSingolo() = 0;
};

class Melanzana : public Prodotto {
public:
	double getPrezzoSingolo() override {
		return 0.23; 
	}
	double getPesoSingolo() override {
		return 0.350;
	}

};

class Carota : public Prodotto {
public:
	double getPrezzoSingolo() override {
		return 0.15; 
	}
	double getPesoSingolo() override {
		return 0.100;
	}

};

class FornoMicroonde : public Prodotto {
public:
	double getPrezzoSingolo() override {
		return 100.00; 
	}
	double getPesoSingolo() override {
		return 10.5;
	}

};

class Scopa : public Prodotto {
public:
	double getPrezzoSingolo() override {
		return 15.00; 
	}
	double getPesoSingolo() override {
		return 0.250;
	}

};

class Patatine : public Prodotto {
public:
	double getPrezzoSingolo() override {
		return 1.20; 
	}
	double getPesoSingolo() override {
		return 0.150;
	}

};

class Carrello {
private:
	map<Prodotto*, int> carrello;
public:
	void aggiungiProdotto(Prodotto *prodotto, int quantita) {
		carrello.emplace(prodotto, quantita);
	}
	double getSpesa() {
		double spesa = 0;
		for(map<Prodotto*, int>::iterator it = carrello.begin(); it != carrello.end(); it++) {
			spesa += it->first->getPrezzoSingolo() * it->second;
		}
		return spesa;
	}
	double getPeso() {
		double peso = 0;
		for(map<Prodotto*, int>::iterator it = carrello.begin(); it != carrello.end(); it++) {
			peso += it->first->getPesoSingolo() * it->second;
		}
		return peso;
	}
};



int main()
{
	Carrello carrello;

	carrello.aggiungiProdotto(new Melanzana(), 4);
	carrello.aggiungiProdotto(new FornoMicroonde(), 1);
	carrello.aggiungiProdotto(new Patatine(), 4);
	carrello.aggiungiProdotto(new Carota(), 4);
	carrello.aggiungiProdotto(new Scopa(), 2);
	carrello.aggiungiProdotto(new Scopa(), 1);
	carrello.aggiungiProdotto(new Carota(), 12);

	cout << "Spesa totale: " << carrello.getSpesa() << endl << "Peso totale: " << carrello.getPeso();

	return 0;
}