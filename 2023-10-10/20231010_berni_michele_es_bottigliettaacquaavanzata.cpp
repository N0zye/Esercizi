#include <iostream>
#include "string.h"

using namespace std;


class BottigliettaAcquaAvanzata {
private:
    int quantitaAcqua, numeroRiempimenti, numeroSvuotamenti, capienza;
    string etichetta;
public:
    BottigliettaAcquaAvanzata(int max, string eti){
        quantitaAcqua = 0;
        numeroRiempimenti = 0;
        numeroSvuotamenti = 0;
        capienza = max;
        etichetta = eti;
    }
    void riempiBottiglietta(int quantita){
        if (quantita > capienza-quantitaAcqua) {
            cout << "E' stata inserita troppa acqua, la bottiglia e' piena ma sono stati sprecati " << (quantita - (capienza-quantitaAcqua)) << " ml di acqua" << endl;
            quantitaAcqua = capienza;
            numeroRiempimenti++;
        } else {
            quantitaAcqua += quantita;
            numeroRiempimenti++;
        }
    }
    void beviAcqua(int quantita) {
        if (quantita > quantitaAcqua) {
            cout << "Hai svuotato la bottiglietta e hai ancora sete" << endl;
            quantitaAcqua = 0;
            numeroSvuotamenti++;
        } else {
            quantitaAcqua -= quantita;
            numeroSvuotamenti++;
        }
    }
    int getQuantitaAcqua(){
        return quantitaAcqua;
    }
    float getPercentualeRiempimento() {
        return ((float)quantitaAcqua/capienza)*100;
    }
    int getNumeroRiempimenti() {
        return numeroRiempimenti;
    }
    int getNumeroSvuotamenti() {
        return numeroSvuotamenti;
    }
    
};

int main()
{
    BottigliettaAcquaAvanzata b(1000, "Bottiglia");
    cout << "Acqua presente: " << b.getQuantitaAcqua() << "\nLa bottiglia e' piena al " << b.getPercentualeRiempimento() << "%\n";
    b.riempiBottiglietta(2000);
    cout << "Acqua presente: " << b.getQuantitaAcqua() << "\nLa bottiglia e' piena al " << b.getPercentualeRiempimento() << "%\n";
    b.beviAcqua(1005);
    cout << "Acqua presente: " << b.getQuantitaAcqua() << "\nLa bottiglia e' piena al " << b.getPercentualeRiempimento() << "%\n";
    b.riempiBottiglietta(750);
    cout << "Acqua presente: " << b.getQuantitaAcqua() << "\nLa bottiglia e' piena al " << b.getPercentualeRiempimento() << "%\n";
    b.beviAcqua(250);
    cout << "Acqua presente: " << b.getQuantitaAcqua() << "\nLa bottiglia e' piena al " << b.getPercentualeRiempimento() << "%\n";
    cout << "In totale la bottiglietta e' stata riempita " << b.getNumeroRiempimenti() << " volte e svuotata " << b.getNumeroSvuotamenti() << " volte" << endl;
   
    return 0;
}