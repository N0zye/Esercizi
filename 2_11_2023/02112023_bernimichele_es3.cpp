#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

/*3. Esercizio sulla classe PianoCottura in C++:

Implementa una classe `PianoCottura` che possa gestire una superficie di cottura con sensori di temperatura per ogni zona e un timer per ciascuna zona. Ogni zona può essere controllata individualmente e può essere impostata per cuocere o riscaldare a una temperatura specifica per un certo periodo di tempo. Aggiungi i seguenti metodi:

- `ImpostaTemperaturaZona(int numeroZona, int temp)`: imposta la temperatura per una zona specifica.
- `ImpostaTimerZona(int numeroZona, int tempo)`: imposta il timer per una zona specifica in minuti.
- `AttivaZona(int numeroZona)`: attiva una zona specifica.
- `DisattivaZona(int numeroZona)`: disattiva una zona specifica.
- `AvviaCotturaZona(int numeroZona)`: avvia la cottura per una zona specifica usando la temperatura e il timer impostati.
- `ArrestaCotturaZona(int numeroZona)`: arresta la cottura per una zona specifica.*/

#define TEMPERATURA_AMBIENTE 22

class Zona{
private:
	bool accesa;
	int temperatura;
	float timerMinuti;
	void timerLoop() {
		int durataTimerSecondi = timerMinuti*60;
		int COPIATIMERSECONDI = durataTimerSecondi;
		while(accesa && durataTimerSecondi > 0) {			
			durataTimerSecondi--;
			if ((COPIATIMERSECONDI - durataTimerSecondi) % 6 == 0) {
				timerMinuti -= 0.1;
			}
			this_thread::sleep_for(chrono::seconds(1));
		}
		accesa = false;
		timerMinuti = -1;
		cout << "Timer terminato" << endl;
	}
public:
	Zona() : accesa(false), temperatura(TEMPERATURA_AMBIENTE), timerMinuti(-1) {}
	void impostaTemperatura(int temperatura) {
		this->temperatura = temperatura;
	}
	void impostaTimer(int tempoMinuti) {
		if (accesa) {
			cerr << "Impossibile modificare il timer di una zona gia accesa" << endl;
			return;
		}
		timerMinuti = tempoMinuti;
	}
	void accendi() {
		accesa = true;
		if (timerMinuti < 0) { //Accensione senza timer
			return;
		}
		thread t(&Zona::timerLoop, this);
		t.detach();
	}
	void spegni() {
		accesa = false;
	}
	int getTemperatura() {
		return temperatura;
	}
	float getTimerMinuti() {
		return timerMinuti;
	}
};

class PianoCottura{
private:
	int numZone;
	Zona *zone;
public:
	PianoCottura(int numeroZone) {
		numZone = numeroZone;
		zone = new Zona[numZone];
	}
	~PianoCottura() {
		delete(zone);
	}
	void accendiZona(int numeroZona) {
		numeroZona--;
		zone[numeroZona].accendi();
	}
	void spegniZona(int numeroZona) {
		numeroZona--;
		zone[numeroZona].spegni();
	}
	void impostaTimerZona(int numeroZona, int durataMinuti){
		numeroZona--;
		zone[numeroZona].impostaTimer(durataMinuti);
	}
	void impostaTemperaturaZona(int numeroZona, int temperatura) {
		numeroZona--;
		zone[numeroZona].impostaTemperatura(temperatura);
	}
	int LeggiTemperaturaZona(int numeroZona) {
		numeroZona--;
		return zone[numeroZona].getTemperatura();
	}
	float leggiTimerMinutiZona(int numeroZona){
		numeroZona--;
		return zone[numeroZona].getTimerMinuti();
	}
};


int main()
{
	PianoCottura p1(3);
	p1.impostaTimerZona(1, 2);
	p1.impostaTemperaturaZona(1, 100);
	cout << "timer: " << p1.leggiTimerMinutiZona(1) << endl;
	p1.accendiZona(1);
	this_thread::sleep_for(chrono::seconds(30));
	cout << "timer: " << p1.leggiTimerMinutiZona(1) << " minuti" << endl;
	p1.spegniZona(1);
	return 0;
}