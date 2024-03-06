#include <iostream>

/*
Scrivi una classe Contatore che tenga traccia del numero di visite a un sito web.
La classe dovrebbe includere un metodo per incrementare il conteggio delle visite e un metodo per ottenere il numero totale
di visite fino a quel momento. Inoltre, deve essere possibile reimpostare il conteggio delle visite a zero.
Progettare e implementare la classe Contatore in modo efficiente e scrivere un programma di test per verificarne il 
funzionamento.
*/

using namespace std;


class Contatore {
private:
    int numeroVisite;
public:
    Contatore() : numeroVisite(0) {}
    void incrementaNVisite() {
        ++numeroVisite;
    }
    int ottieniNumeroVisite() {
        return numeroVisite;
    }
    void resetNVisite() {
        numeroVisite = 0;
    }
};

int main() {

    Contatore c;

    c.incrementaNVisite();
    cout << c.ottieniNumeroVisite();
    c.resetNVisite();
}