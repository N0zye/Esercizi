#include <iostream>

using namespace std;

class Nodo {
public:
    int value;
    Nodo* next;
    Nodo(int value) : value(value), next(nullptr) {}
};

class Lista {
private:
    int numero_elementi;
    Nodo* testa;
public:
    Lista() {
        testa = nullptr;
        numero_elementi = 0;
    }
    void inserisciInTesta(int valore) {
        Nodo* nuovoNodo = new Nodo(valore);
        nuovoNodo->next = testa;
        testa = nuovoNodo;
        numero_elementi++;
    }
    void eliminaInTesta() {
        if(testa == nullptr) {
            cout << "Errore! la lista e' vuota" << endl;
            return;
        }
        Nodo* nuovoNodo = testa;
        testa = testa->next;
        delete nuovoNodo;
        numero_elementi --;
    }
    void inserisciInCoda(int valore) {
        Nodo* nuovoNodo = new Nodo(valore);
        if (isVuoto()) {
            testa = nuovoNodo;
            return;
        }
        
        Nodo* pn = testa;
        while (pn->next != nullptr) {
            pn = pn->next;
        } // Dopo il while pn rappresenta la coda della lista
        pn->next = nuovoNodo;
        numero_elementi++;
    }
    void eliminaInCoda() {

        if (isVuoto()) {
            cout << "Errore! la lista e' vuota" << endl;
            return;
        }
        if (getNumeroElementi() == 1) {
            eliminaInTesta();
            return;
        }
        
        Nodo* pn = testa;
        while (pn->next->next != nullptr) {
            pn = pn->next;
        } // Dopo il while pn rappresenta il nodo prima della coda (penultimo)
        delete pn->next;
        pn->next = nullptr;
        numero_elementi--;
    }
    void inserisciInPos(int i, int valore) {
        if(i < 0 || i > getNumeroElementi()) {
            cout << "Errore! l'indice fornito non e' valido" << endl;
            return;
        }
        if(i == 0) {
            inserisciInTesta(valore);
            return;
        }
        Nodo* pn = testa;
        for (int j = 0; j < i-1; j++) {
            pn = pn->next;
        } // Dopo il for pn rappresenta il nodo prima del nodo i

        Nodo* nuovoNodo = new Nodo(valore);
        nuovoNodo->next = pn->next;
        pn->next = nuovoNodo;
        numero_elementi++;
    }

    void eliminaLaPos(int i) {
        if(i < 0 || i >= getNumeroElementi()) {
            cout << "Errore! l'indice fornito non e' valido" << endl;
            return;
        }
        if(i == 0) {
            eliminaInTesta();
            return;
        }
        Nodo* pn = testa;
        for (int j = 0; j < i-1; j++) {
            pn = pn->next;
        } // Dopo il for pn rappresenta il nodo prima del nodo i

        Nodo* nuovoNodo = pn->next;
        pn->next = nuovoNodo->next;
        delete nuovoNodo;
        numero_elementi--;
    }

    void stampaElementi() {
        Nodo* pn = testa;
        while (pn != nullptr) {
            cout << pn->value << ", ";
            pn = pn->next;
        }
        cout << endl;
    }
    int getElementoInTesta() {
        if(isVuoto()) {
            cout << "Errore! la lista e' vuota" << endl;
            return -1;
        }
        return testa->value;
    }
    int getElementoInCoda() {
        if(isVuoto()) {
            cout << "Errore! la lista e' vuota" << endl;
            return -1;
        }
        Nodo* pn = testa;
        while (pn->next != nullptr) {
            pn = pn->next;
        } // Dopo il while pn rappresenta la coda della lista
        return pn->value;
    }
    bool isVuoto() {
        if(numero_elementi == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    int getNumeroElementi() {
        return numero_elementi;
    }
};


int main() {

    Lista l;

    l.inserisciInTesta(10);
    l.stampaElementi();
    cout << "numero elementi: " << l.getNumeroElementi() << "   testa: " << l.getElementoInTesta() << "     coda: " << l.getElementoInCoda()<<endl;
    l.inserisciInTesta(2);
    l.stampaElementi();
    cout << "numero elementi: " << l.getNumeroElementi() << "   testa: " << l.getElementoInTesta() << "     coda: " << l.getElementoInCoda()<<endl;

    return 0;
}