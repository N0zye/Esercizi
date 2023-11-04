#include <iostream>

using namespace std;
/*1. Esercizio sulla classe LampadinaLed in C++:

Crea una classe `LampadinaLed` che rappresenti una lampadina a LED.La classe dovrebbe avere due stati possibili : acceso e spento.Implementa i seguenti metodi :

-`Accendi()`: accende la lampadina.
-`Spegni()`: spegne la lampadina.
-`Stato()`: restituisce lo stato attuale della lampadina(acceso o spento).*/

class LampadinaLed {
    bool accesa;
public:
    LampadinaLed() {
        accesa = false;
    }
    void accendi() {
        accesa = true;
    }
    void spegni() {
        accesa = false;
    }
    bool stato() {
        return accesa;
    }
};

int main()
{
	LampadinaLed l1;
	cout << "La lampadina e' " << (l1.stato() ? "Accesa" : "Spenta") << endl;
    l1.accendi();
    cout << "La lampadina e' " << (l1.stato() ? "Accesa" : "Spenta") << endl;
    l1.spegni();
    cout << "La lampadina e' " << (l1.stato() ? "Accesa" : "Spenta") << endl;

	return 0;
}