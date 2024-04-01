#include <iostream>

using namespace std;
/*
**Negozio di alimentari:**
Descrizione dell'esercizio:
Scrivi una classe `NegozioAlimentari` che gestisca l'inventario di un negozio di alimentari. Il negozio ha una capacità massima di prodotti che può gestire, determinata dal numero massimo di prodotti che può contenere. I prodotti hanno un nome, un prezzo e una quantità disponibile. La classe `NegozioAlimentari` deve includere i seguenti metodi:

   - `aggiungiProdotto(string nome, double prezzo, int quantita)`: Aggiunge un prodotto al negozio con il nome, il prezzo e la quantità specificati. Se il negozio è pieno, non aggiunge il prodotto.
   
   - `vendiProdotto(string nome)`: Permette di vendere un prodotto dal negozio. Riduce la quantità disponibile del prodotto venduto. Se il prodotto non è disponibile nel negozio, restituisce un messaggio appropriato.
   
   - `riordinaProdotto(string nome, int quantita)`: Aggiunge quantità aggiuntiva di un prodotto al negozio. Se il prodotto non è presente nel negozio, lo aggiunge con la quantità specificata.

   - `getNumeroProdotti()` e `getCapacitaMassima()`: Restituiscono rispettivamente il numero di prodotti attualmente nel negozio e la capacità massima del negozio.*/

class Prodotto {
private:
    string nome;
    float prezzo;
    int quantita;
public:
    Prodotto();
    Prodotto(string n, float p, int quantita_iniziale) {
        nome = n;
        prezzo = p;
        quantita = quantita_iniziale;
    }
    string getNome() {
        return nome;
    }
    float getPrezzo() {
        return prezzo;
    }
    int getQuantita() {
        return quantita;
    }
    void vendi(int numero_da_vendere) {
        if (numero_da_vendere > quantita) {
            cout << "non se ne possono vendere cosi tanti, non ne hai a sufficienza" << endl;
        } else {
            quantita -= numero_da_vendere;
        }
    }
    void rifornisci(int numero_da_rifornire) {
        quantita += numero_da_rifornire;
    }
};

#define MAX_PRODOTTI_DIVERSI 10

class NegozioAlimentare {
private:
    Prodotto magazzino[MAX_PRODOTTI_DIVERSI] = {};
    int numero_prodotti_diversi;
    int capacita_max;
public:
    NegozioAlimentare(int capacita) {
        numero_prodotti_diversi = 0;
        capacita_max = capacita;
    }
    void aggiungiProdotto(Prodotto p) {
        magazzino[numero_prodotti_diversi] = p;
        numero_prodotti_diversi++;
    }
};

int main() {

}