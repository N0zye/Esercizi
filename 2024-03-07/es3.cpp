#include <iostream>

using namespace std;

/*
**Veicoli:**
Descrizione dettagliata dell'esercizio:
   - Crea una classe di base chiamata `Veicolo` che abbia due attributi protetti: `numeroRuote` (int) e `velocitaMassima` (int).
   - Implementa un costruttore per la classe `Veicolo` che accetti i valori per entrambi gli attributi.
   - Aggiungi un metodo virtuale puro chiamato `calcolaVelocita()` che ritorni un intero, per calcolare la velocità massima del veicolo.
   - Crea due classi derivate: `Automobile` e `Bicicletta`.
   - La classe `Automobile` dovrebbe avere un attributo privato aggiuntivo `numeroPorte` (int).
   - Implementa un costruttore per la classe `Automobile` che accetti i valori per tutti gli attributi, inclusi quelli della classe base.
   - Sovrascrivi il metodo `calcolaVelocita()` nella classe `Automobile` per calcolare la velocità massima dell'automobile, considerando anche il numero di porte.
   - La classe `Bicicletta` dovrebbe avere un attributo privato aggiuntivo `tipoTerreno` (string).
   - Implementa un costruttore per la classe `Bicicletta` che accetti i valori per tutti gli attributi, inclusi quelli della classe base.
   - Sovrascrivi il metodo `calcolaVelocita()` nella classe `Bicicletta` per calcolare la velocità massima della bicicletta, considerando il tipo di terreno.
*/

class Veicolo {
protected:
    int numeroRuote, velocitaMassima;
public:
    Veicolo(int nRuote, int velocita_max) {
        numeroRuote = nRuote;
        velocitaMassima = velocita_max;
    }
    void stampaciao() {
        cout << "ciao" << endl;
    }
    virtual int calcolaVelocita() = 0; //note il metodo virtuale implica che la classe (Veicolo sia astratta)
    //se una classe e' astratta non la puoi tenere in mano
};

class Automobile : public Veicolo {
protected:
    int numeroPortiere;
public:
    Automobile(int nRuote, int velocita_max, int nporte) : Veicolo(nRuote, velocita_max){
        numeroPortiere = nporte;
    }
    int calcolaVelocita() override {
        return velocitaMassima-numeroPortiere;
    }
};

class Bicicletta : public Veicolo {
protected:
    string tipo_terreno;
public:
    Bicicletta(int nRuote, int velocita_max) : Veicolo(nRuote, velocita_max){
        tipo_terreno = "asfalto";
    }
    int calcolaVelocita() override {
        if(tipo_terreno == "asfalto") {
            return velocitaMassima;
        }
        else {
            return velocitaMassima/2;
        }
    }
};

class Calcolatrice { //overloading
public:
    int somma(int a, int b) {
        return a+b;
    }

    int somma(int a, int b, int c) {
        return a+b+c;
    }
};

#define MAX 30
int main() {

    Calcolatrice c;

    c.somma(1,2); // il programma deduce da solo quale delle somme usare

    c.somma(1,2,3);

    int arr[10]; // ARRAY DI 10 INTERI

    Veicolo* arrr[10]; //ARRAY DI 10 'FILI' A VEICOLO

    Veicolo* v1 = new Bicicletta(2, 10); // tutte le volte che fai new devi fare anche delete
    Veicolo* v2 = new Automobile(4, 50, 2);

    v1->calcolaVelocita();
    v2->calcolaVelocita();
    v1->stampaciao();
    v2->stampaciao();
    
    //note non si puo fare perche veicolo e'  astratto
    //Veicolo* v3 = new Veicolo(2, 10);
    // senza sapere se v1 o v2 sono una bicicletta o una auto
    // possiamo fare v1.calcolaVelocita()
    delete v1;
}