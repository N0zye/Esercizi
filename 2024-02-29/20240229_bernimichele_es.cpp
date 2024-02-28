#include <iostream>

using namespace std;

/*Creare una classe base "Danzante".
- metodo virtuale void canta() ; // il genere può essere 0 = maschio e 1 = femmina


Creare due classe figlie di "Danzante", la prima "Ballerina" e la seconda "Ballerino".
- metodo void canta() che stampa "ahi" per le femmine e "asi" per i maschi.*/

class Danzante {
private:
    bool genere;
public:
    Danzante (bool genere) : genere(genere) {}
    virtual void canta() = 0;
    bool getGenere() {
        return genere;
    }
};

class Ballerina : public Danzante{
public:
    Ballerina() : Danzante(true) {}
    void canta() override {
        cout << "ahi" << endl;
    }
};

class Ballerino : public Danzante{
public:
    Ballerino() : Danzante(true) {}
    void canta() override {
        cout << "asi" << endl;
    }
};

//note differenza struct-class: struct è default public mentre class private
struct VagoneDanzante {
    Danzante* danzante;
    VagoneDanzante* next;

    VagoneDanzante(Danzante* danzante) : danzante(danzante), next(nullptr){}
};


int main() {

    VagoneDanzante* locomotiva = new VagoneDanzante(new Ballerina);

    VagoneDanzante* pv = locomotiva;

    for (int i = 1; i < 10; i++) {
        pv->next = (i%2==0 ? new VagoneDanzante(new Ballerina) : new VagoneDanzante(new Ballerino));
        pv = pv->next;
    }
    
    pv = locomotiva;

    while (pv != nullptr) {

        pv->danzante->canta();

        pv = pv->next;

    }

    return 0;
}