#include <iostream>

using namespace std;

class Animale {
protected:
    string nome;
    int eta;
public:
    Animale(string n, int age) {
        nome = n;
        eta = age;
    }
    void impostaNome(string nuovo_nome) {
        nome = nuovo_nome;
    }
    void impostaEta(int nuova_eta) {
        eta = nuova_eta;
    }
    string getNome() {
        return nome;
    }
    int getEta() {
        return eta;
    }
    virtual void emettiSuono() =0; // metodo virtuale puro, un metodo senza implementazione
    //rappresenta un azione di un concetto astratto (non conosciamo l'Animale ma i cani e i gatti si)
    //quindi non sappiamo che suono fa un animale generico ma sappiamo che essendo un animale fara un suono
    //il suono viene definito (implementato) attraverso la sovrascrittura (override) nelle classi concrete (Cane e Gatto)
    //ossia delle cose concrete che sono degli animali e in quanto tali emetteranno dei suoni, nel caso del cane un 'bau' e 'miao' per il gatto
};

class Cane : public Animale { // tutti i cani sono degli animali
public:
    Cane(string n, int age) : Animale(n, age){}
    void emettiSuono() override { // sovrascrittura del metodo virtuale, implementando il verso del cane
        cout << "bau" << endl;
    }
};

class Gatto : public Animale {
public:
    Gatto(string n, int age) : Animale(n, age){}
    void emettiSuono() override {// sovrascrittura del metodo virtuale, implementando il verso del gatto
        cout << "miao" << endl;
    }
};

//Altri animali:

class Leone : public Animale{
  public:
    Leone(string n, int age) : Animale(n, age){}
    void emettiSuono() override {
        cout << "grrh" << endl;
    }  
};

class Gallo : public Animale{
  public:
    Gallo(string n, int age) : Animale(n, age){}
    void emettiSuono() override {
        cout << "chicchirichi" << endl;
    }  
};

class Zoo{ //Classe contenitore di tanti animali
private:

    // usiamo i puntatori animale (Animale*) anziche gli animali normali (Animale) perche:
    // perche gli animali sono un concetto astratto e quindi non possiamo tenerli, ma possiamo tenere dei fili
    // o delle scatole chiuse nelle cui non sappiamo se si trova un gatto un cane ecc ma sappiamo che ci si trova un animale
    Animale* array_di_animali[100]; // array di max 100 animali, ma non sappiamo quanti di preciso ==> 0<=n_animali<=100
    int dimensione_reale; // l'array  e' a dimensione fissa(100)
    // quindi c'e' bisogno di una variable per sapere quanti elementi sui 100 massimi abbiamo
public:
    Zoo() {
        dimensione_reale = 0; //  all'inizio non ci sono animali, quindi la dim reale e' 0
    }
    void aggiungiAnimale(Animale* animale_nuovo) {
        if(dimensione_reale>=100) {
            cout << "Lo zoo e' pieno, non ci stanno piu animali" << endl;
        }
        else{
        array_di_animali[dimensione_reale] = animale_nuovo;
        dimensione_reale++; // ogni volta che aggiungiamo un animale dobbiamo aggiungere 1 alla dim reale
        // per tenere conto del nuovo animale
        }
    }
    void emettiSuono_di_tutti_gli_animali() {
        for (int i = 0; i < dimensione_reale; i++) { //per ogni animale (indicato dal numero reale degli animali)
            array_di_animali[i]->emettiSuono();
            //si usa -> perche l'array non e' di animali (Animale) ma di puntatori ad animali (Animale*), e con i puntatori bisogna usare il simbolo ->
            // mentre con gli oggetti normali (che non sono puntatori) si usa il '.'
    
        }
        
    }
};

int main() {

    

    /*Animale* a1 = new Cane("dobby", 1);
    Animale* a2 = new Gatto("bho", 12);

    a1->emettiSuono();
    a2->emettiSuono();
    
    delete a1; // ogni volta che compare la parola 'new' deve comparire anche il delete per liberare la memoria occupata dal new
    delete a2; // quindi se abbiamo creato un 'new' gatto e cane (a1 e a2) dovremo eliminarli poi con il 'delete'
    */
}