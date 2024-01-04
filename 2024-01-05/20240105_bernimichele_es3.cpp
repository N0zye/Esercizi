#include <iostream>

using namespace std;

/*BARATTOLO / SALIERA (EREDITARIETA’)
Creare innanzitutto la classe Barattolo che serve per rappresentare dei barattoli caratterizzandoli col volume e la quantità di contenuto effettivamente presente nei barattoli, scrivere anche i metodi necessari.
Successivamente realizzare la classe saliera, che rappresenta i barattoli adibiti a contenere e dosare il sale, ogni saliera ha un tot numero di buchini da ognuno dei quali quando viene capovolta esce una quantità unitaria di sale.
Create le classi si realizzi un main per testarle.
Si proceda con due realizzazioni distinte delle classi, la prima volta senza usare protected, la seconda usando protected.*/

class Barattolo {
protected:
	int volume, quantitaProdotto;
public:
	Barattolo(int volume) : volume(volume), quantitaProdotto(volume) {}
	void riempi() {
		quantitaProdotto = volume;
	}
};

class Saliera : public Barattolo {
protected:
	int numeroBuchi;
public:
	Saliera(int volume, int numeroBuchi) : Barattolo(volume), numeroBuchi(numeroBuchi) {}
	void versa() {
		if(numeroBuchi > quantitaProdotto) {
			cout << "E' finito il sale" << endl;
			quantitaProdotto = 0;
			return;
		}
		quantitaProdotto -= numeroBuchi;
	}
};

int main() {
	Saliera s(10, 3);

	s.versa();
	s.versa();
	s.versa();
	s.versa();
	return 0;
}