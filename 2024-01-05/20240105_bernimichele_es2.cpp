#include <iostream>
#include <cmath>

using namespace std;

/*AUTOMOBILINA / AUTOMOBILINA POLIZIA (EREDITARIETA’) 
Creare una classe per rappresentare un’automobilina telecomandata a batteria.
L’automobilina si potrà muovere nelle quattro direzioni su un tabellone bidimensionale con caselle quadrate, la sua posizione sarà memorizzata tramite le due coordinate.
Ogni automobilina avrà una certa carica della batteria che si consumerà come segue: per ogni casella in cui si muove consumerà l’1% della batteria, qualora si muova in una sola volta di almeno 5 celle consumerà l’1% in meno ogni 5 celle (ad esempio se si muove di 13 celle consumerà l’11% di batteria).
Creare la classe automobilina della polizia, che avrà le stesse caratteristiche delle automobiline normali, ma in più avrà la sirena, che potrà essere azionata.
Quando sarà azionata la sirena la carica scenderà del 2%.*/

class Automobilina {
protected:
	float batteria;
	int posX, posY;
public:
	Automobilina() : batteria(10.0), posX(0), posY(0) {}
	void goTo(int newPosX, int newPosY) {
		float distanza = sqrt(pow(posX-newPosX,2) + pow(posY-newPosY,2));
		if (distanza >  (batteria + int(distanza / 5))) {
			posX += batteria*newPosX / distanza;
			posY += batteria*newPosY / distanza;
			batteria = 0;
			cout << "La battreria non e' bastata per arrivare a destinazione" << endl;
			return;
		}
		posX = newPosX;
		posY = newPosY;
		batteria -= distanza;
		batteria += int(distanza / 5);	
	}
};

class AutomobilinaDellaPolizia : public Automobilina {
protected:
	bool sirenaIsAccesa;
public:
	AutomobilinaDellaPolizia() : Automobilina(), sirenaIsAccesa(false) {}
	void accendiSirena() {
		if (batteria < 2.0) {
			cout << "Batteria insufficiente, impossibile accendere la sirena" << endl;
			return;
		}
		sirenaIsAccesa = true;		
	}
	void spegniSirena() {
		sirenaIsAccesa = false;
	}
};

int main() {

	Automobilina a;

	a.goTo(1, 0);
	a.goTo(10, 0);

	return 0;
}