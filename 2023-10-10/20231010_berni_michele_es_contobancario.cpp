#include <iostream>
#include "string.h"

using namespace std;


class AccountBancario {
private:
    float saldo;
    string titolare;
public:
    AccountBancario(float salini, string tit){
        saldo = salini;
        titolare = tit;
    }
    void deposito(float quantita) {
        saldo += quantita;
    }
    void prelievo(float quantita) {
        if (quantita > saldo) {
            cout << "Impossibile effettuare il prelievo, credito insufficiente" << endl;
        } else {
            saldo -= quantita;
        }
    }
    void calcolaInteressi(float tasso) {
        //Interesse = (Capitale depositato * tasso di interesse netto annuo * (tempo in giorni ??)) / 36500.
        saldo += (saldo * tasso * 365)/ 36500;
    }
    float getSaldo() {
        return saldo;
    }
    std::string getTitolare() {
        return titolare;
    }
    
};

int main()
{
    AccountBancario a1(10000, "Berni");

    cout << "L'account bancario di " << a1.getTitolare() << " contiene " << a1.getSaldo() << "E" << endl;
    a1.deposito(20000);
    cout << "L'account bancario di " << a1.getTitolare() << " contiene " << a1.getSaldo() << "E" << endl;
    a1.calcolaInteressi(3.5);
    cout << "L'account bancario di " << a1.getTitolare() << " contiene " << a1.getSaldo() << "E" << endl;
    a1.prelievo(15000);
    cout << "L'account bancario di " << a1.getTitolare() << " contiene " << a1.getSaldo() << "E" << endl;
    return 0;
}