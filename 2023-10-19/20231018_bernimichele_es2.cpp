#include <iostream>

using namespace std;

/*2. Esercizio sulla classe Fucile in C++:

Definisci una classe `Fucile` che rappresenti un fucile. Questa classe dovrebbe avere un attributo che indica se il fucile � caricato o meno. Implementa i seguenti metodi:

- `Carica()`: carica il fucile.
- `Sparo()`: se il fucile � caricato, stampa "Bang!" e imposta lo stato del fucile come scarico. Se il fucile non � caricato, stampa un messaggio che indica di caricarlo prima di sparare.*/

class Fucile {
private:
    bool carico;
public:
    Fucile() {
        carico = false;
    }
    void carica() {
        carico = true;
    }
    void sparo() {
        cout << (carico ? "Bang!\n" : "Il fucile e' scarico\n");
        carico = false;
    }
};

int main()
{
    Fucile f1;
    f1.sparo();
    f1.carica();
    f1.sparo();

    return 0;
}