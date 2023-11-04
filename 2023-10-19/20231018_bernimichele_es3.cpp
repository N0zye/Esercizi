#include <iostream>

using namespace std;

/*3. Esercizio sulla classe PianoCottura in C++:**

Realizza una classe `PianoCottura` che rappresenti un piano cottura. Questa classe dovrebbe avere un attributo che rappresenta la temperatura del piano cottura. Implementa i seguenti metodi:

- `ImpostaTemperatura(int temp)`: imposta la temperatura del piano cottura al valore specificato.
- `LeggiTemperatura()`: restituisce la temperatura attuale del piano cottura.*/

class PianoCottura {
private:
	int temperatura;
public:
	PianoCottura() {
		temperatura = 25;
	}
	void impostaTemperatura(int temp) {
		temperatura = temp;
	}
	int leggiTemperatura() {
		return temperatura;
	}
	
};

int main()
{
	PianoCottura p;
	cout << "Il piano e' a " << p.leggiTemperatura() << " gradi\n";
	p.impostaTemperatura(100);
	cout << "Il piano e' a " << p.leggiTemperatura() << " gradi\n";

	return 0;
}