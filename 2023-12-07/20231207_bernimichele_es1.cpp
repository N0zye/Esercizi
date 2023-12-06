#include <iostream>

using namespace std;

/*Esercizio 1 - Bicicletta
==================
"Creare le classi Bicicletta e BiciclettaConCambio in relazione attraverso il vincolo di ereditarietà. 
Entrambe sono dotate di conta-metri inizialmente azzerati. 
Mentre la bicicletta normale avanza di un metro ad ogni pedalata, la bicicletta con cambio avanza in base al rapporto selezionato. 
In modo semplificato, ad ogni pedalata si percorrono N metri, dove N è il valore del rapporto scelto. Ad esempio, se si è nel rapporto uno, si avanza di un metro; 
se si è nel rapporto due, si avanzano due metri, e così via."
*/

class Bicicletta {
protected:
    int metriPercorsi;

public:
    Bicicletta() : metriPercorsi(0) {}

    virtual void pedala() {
        metriPercorsi++;
    }
};

class BiciclettaConCambio : public Bicicletta {
private:
    int rapporto;

public:
    BiciclettaConCambio() : Bicicletta(), rapporto(1) {}

    void impostaRapporto(int newRapporto) {
        rapporto = newRapporto;
    }

    void pedala() override {
        metriPercorsi += rapporto;
    }
};


int main()
{
	Bicicletta b1;
	BiciclettaConCambio bcc1;

	b1.pedala();
	bcc1.impostaRapporto(10);
	bcc1.pedala();


	return 0;
}