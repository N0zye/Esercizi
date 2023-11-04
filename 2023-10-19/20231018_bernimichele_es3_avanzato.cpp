#include <iostream>

using namespace std;

/*3. Esercizio sulla classe PianoCottura in C++:

Implementa una classe `PianoCottura` che possa gestire non solo una singola zona di cottura, ma un'intera superficie con più zone. Ogni zona ha la sua temperatura e può essere accesa o spenta individualmente. Aggiungi i seguenti metodi:

- `AccendiZona(int numeroZona)`: accende una zona specifica.
- `SpegniZona(int numeroZona)`: spegne una zona specifica.
- `ImpostaTemperaturaZona(int numeroZona, int temp)`: imposta la temperatura per una zona specifica.
- `LeggiTemperaturaZona(int numeroZona)`: restituisce la temperatura della zona specificata.*/

#define MAX_ZONE 100
#define TEMPERATURA_AMBIENTE 25

class Zona {
private:
	int temperatura;
	bool accesa;
public:
	Zona() {
		temperatura = TEMPERATURA_AMBIENTE;
		accesa = false;
	}
	void accendi() {
		accesa = true;
	}
	void spegni() {
		accesa = false;
	}
	void impostaTemperatura(int temp) {
		if (accesa) {
			temperatura = temp;
		}
		else {
			cout << "impossibile impostare la temperatura, la zona e' spenta\n";
		}
	}
	int getTemperatura() {
		return temperatura;
	}
};

class PianoCottura {
private:
	int numZone;
	Zona* zona;
public:
	PianoCottura(int nZone) {
		numZone = nZone;
		zona = new Zona[numZone];
	}
	void accendiZona(int numeroZona) {
		zona[numeroZona].accendi();
	}
	void spegniZona(int numeroZona) {
		zona[numeroZona].spegni();
	}
	void impostaTemperaturaZona(int numeroZona, int temp) {
		zona[numeroZona].impostaTemperatura(temp);
	}
	void LeggiTemperaturaZona(int numeroZona) {
		zona[numeroZona].getTemperatura();
	}
};

int main()
{
	return 0;
}