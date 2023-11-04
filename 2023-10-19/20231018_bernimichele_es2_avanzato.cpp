#include <iostream>

using namespace std;

/*2. Esercizio sulla classe Fucile in C++:

Raffina la classe `Fucile` introducendo la possibilit� di sparare in modalit� automatica o semiautomatica. Aggiungi i seguenti metodi:

- `SparoAutomatico()`: fa sparare il fucile automaticamente finch� non � scarico.
- `SparoSingolo()`: permette di sparare un colpo alla volta in modalit� semiautomatica.
- `Ricarica()`: ricarica il fucile se � vuoto.*/

class Fucile {
private:
    int dimCaricatore, proiettili;
public:
    Fucile(int maxCaricatore) {
        dimCaricatore = maxCaricatore;
        proiettili = 0;
    }
    void sparoSingolo() {
        if (proiettili > 0) {
            cout << "Bang!\n";
            proiettili--;
        }
        else {
            cout << "Il fucile e' scarico\n";
        }
    }
    void sparoAutomatico() {
        while (proiettili > 0) {
            sparoSingolo();
        }
        cout << "Il fucile e' scarico\n";
    }
    void carica() {
        proiettili = dimCaricatore;
    }
};

int main() 
{
    Fucile f1(5);
    f1.sparoSingolo();
    f1.sparoAutomatico();
    f1.carica();
    f1.sparoSingolo();
    f1.sparoAutomatico();

	return 0;
}