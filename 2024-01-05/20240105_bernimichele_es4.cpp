#include <iostream>

using namespace std;

/*TAPPARELLA / TAPPARELLA ELETTRICA (EREDITARIETA’)
Creare una classe tapparella per rappresentare le tapparelle delle finestre, la classe deve memorizzare le dimensioni della finestra in cui è inserita la tapparella e deve avere dei metodi per far scendere o salire di un tot la tapparella.
Considerare poi delle tapparelle elettriche che permettono pigiando degli appositi bottoni di far scendere o salire completamente le tapparelle.*/

class Tapparella {
protected:
	int altezza;
	int currentLivello;
public:
	Tapparella(int altezza) : altezza(altezza), currentLivello(altezza) {}
	void tiraSuDi(int quanto) {
		if (quanto > altezza-currentLivello) {
			cout << "Hai sbattuto la tapparella nel soffitto" << endl;
			currentLivello = altezza;
			return;
		}
		currentLivello += quanto;
	}
	void tiraGiuDi(int quanto) {
		if (quanto > currentLivello) {
			cout << "Hai sbattuto la tapparella nel pavimento" << endl;
			currentLivello = 0;
			return;
		}
		currentLivello -= quanto;
	}
};

class TapparellaElettrica : public Tapparella{
public:
	TapparellaElettrica(int altezza) : Tapparella(altezza) {}
	void tiraSu() {
		currentLivello = altezza;
	}
	void tiraGiu() {
		currentLivello = 0;
	}
};

int main() {

	return 0;
}