#include <iostream>

using namespace std;

/*Esercizio 2 - Borraccia
==================
"Creare le classi Borraccia e BorracciaConGusto in relazione attraverso il vincolo di ereditarietà. 
Entrambe sono dotate di una capacità totale e di una quantità attuale, espresse in unità. 
La BorracciaConGusto deve gestire la caratteristica del "gusto", che si attenua ad ogni sorso fino a scomparire
 dopo cento sorsi. Ogni sorso riduce il contenuto di una unità."
*/

class Borraccia {
protected:
	int capacitaMax, quantitaAttuale;
public:
	Borraccia(int capacitaMax) : capacitaMax(capacitaMax), quantitaAttuale(capacitaMax) {}
	virtual void bevi(){
		if(quantitaAttuale <= 0) {
			cout << "La bottiglia e' vuota, impossibile bere" << endl;
			return;
		}
		quantitaAttuale--;
	}
	void riempi(){
		quantitaAttuale = capacitaMax;
	}
	int getQuantitaAttuale() {
		return quantitaAttuale;
	}
};

class BorracciaConGusto : public Borraccia{
private:
	int gusto;
public:
	BorracciaConGusto(int capacitaMax) : Borraccia(capacitaMax), gusto(100) {}
	void bevi() override{
		if(gusto <= 0) {
			cout << "L'acqua non ha piu sapore" << endl;
			return;
		}
		gusto--;
		Borraccia::bevi();
	}
};

int main()
{
	BorracciaConGusto b(110);
	for(int i = 0; i < 110; i++) {
		b.bevi();
	}
	b.bevi();
	return 0;
}