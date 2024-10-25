#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>    
#include <conio.h>  // for getch()

using namespace std;

enum TicketType {
	FM,  //Farmacia Medicinali
	SP,  //Sospesi Prescrizione
	CI   //Cosmetici e Integratori
};

string ticketTypeToString(TicketType type) {
    switch(type) {
        case SP: return "SP";
        case FM: return "FM";
        case CI: return "CI";
        default: return "Unknown";
    }
}

class Ticket {
private:
	TicketType prefisso;
	int numero;
public:
    Ticket() {}
	Ticket(TicketType prefisso, int numero) : prefisso(prefisso), numero(numero) {}
	bool operator <(const Ticket& rhs) const {
		if (prefisso == rhs.prefisso) {
			return numero>rhs.numero;
		} else if (prefisso == SP && rhs.prefisso == FM) {
			return false;
		} else {
			return true;
		}
	}
    TicketType getPrefisso() const {
        return prefisso;
    }
    int getNumero() const {
        return numero;
    }
    void stampaTicket() const {
        cout << ticketTypeToString(prefisso) << numero;
    }
};

class EliminaCoda {
public:
	EliminaCoda(int numCodeMedicinali, int numCodeCosmesi) : contatoreMedicinali(1), contatoreCosmesi(1), contatoreSospesi(1) {
		code["Farmacia"] = vector<priority_queue<Ticket>>(numCodeMedicinali);
		code["Cosmetici"] = vector<priority_queue<Ticket>>(numCodeCosmesi);
	}
	void aggiungiPersona(TicketType prefisso) {
        Ticket t;
        switch (prefisso) {
        case FM:
            t = Ticket(prefisso, contatoreMedicinali++);
            break;
        case SP:
            t = Ticket(prefisso, contatoreSospesi++);
            break;
        case CI:
            t = Ticket(prefisso, contatoreCosmesi++);
            break;
        }
        if (prefisso != CI)  {
            code.at("Farmacia").at(trovaIndiceMinSize("Farmacia")).push(t);
        } else {
            code.at("Cosmetici").at(trovaIndiceMinSize("Cosmetici")).push(t);
        }     
	}
    void serviPersona(string cassa, int numeroCassa) {
        if(cassa != "Farmacia" && cassa != "Cosmetici") {
            throw invalid_argument("Cassa \"" + cassa + "\" non valida");
        }
        if (numeroCassa < 1 || numeroCassa > (int)code.at(cassa).size()) {
            throw out_of_range("Numero cassa \"" + to_string(numeroCassa) + "\" non valido");
        }
        if(code.at(cassa).at(numeroCassa-1).empty()) {
            throw out_of_range("Cassa vuota");
        }
        code.at(cassa).at(numeroCassa-1).pop();
    }
    void stampaCode() {
        cout << "Farmacia" << endl;
        for (int i = 0; i<(int)code.at("Farmacia").size(); i++) {
            cout << "Cassa " << i+1 << ": ";
            if (code.at("Farmacia").at(i).empty()) {
                cout << "vuota" << endl;
            } else {
                priority_queue<Ticket> coda = code.at("Farmacia").at(i);
                while (!coda.empty()) {
                    coda.top().stampaTicket();
                    coda.pop();
                    cout << " ";
                }
                cout << endl;
            }
        }
        cout << "---------" << endl << endl;
        cout << "Cosmetici" << endl;
        for (int i = 0; i<(int)code.at("Cosmetici").size(); i++) {
            cout << "Cassa " << i+1 << ": ";
            if (code.at("Cosmetici").at(i).empty()) {
                cout << "vuota" << endl;
            } else {
                priority_queue<Ticket> coda = code.at("Cosmetici").at(i);
                while (!coda.empty()) {
                    coda.top().stampaTicket();
                    coda.pop();
                    cout << " ";
                }
                cout << endl;
            }
        } 
    }
private:
	int contatoreMedicinali, contatoreCosmesi, contatoreSospesi;
	unordered_map<string, vector<priority_queue<Ticket>>> code;
	
	int trovaIndiceMinSize(string tipoCassa) {
		vector<priority_queue<Ticket>> v = code[tipoCassa];
		int iMin = 0;
		int minSize = v.at(0).size();
		for (int i = 1; i<(int)v.size();i++) {
			if ((int)v.at(i).size() < minSize) {
				minSize = (int)v.at(i).size();
				iMin=i;
			}
            if ((int)v.at(i).size() == minSize) {
                if (tipoCassa == "Farmacia") {
                    iMin = (lessSP(v.at(i), v.at(iMin))) ? i : iMin;
                    lessSP(v.at(i), v.at(iMin));
                }
            }
		}
		return iMin;
	}
    bool lessSP(priority_queue<Ticket> lhs, priority_queue<Ticket> rhs) {
        while (!lhs.empty() && !rhs.empty()) {
            if (lhs.top().getPrefisso() == SP && rhs.top().getPrefisso() == SP) {
                lhs.pop();
                rhs.pop();
            }
            else if (lhs.top().getPrefisso() != SP && rhs.top().getPrefisso() == SP) {
                return true;
            }
            else if (lhs.top().getPrefisso() == SP && rhs.top().getPrefisso() != SP) {
                return false;
            }
            else {
                break;
            }
        }
        return false;
    }
};

void stampaMenuPrincipale(EliminaCoda e) {
    system("cls");
    e.stampaCode();
    cout << "---------" << endl << endl << "Menu Principale" << endl; 
    cout << "0. Esci" << endl;
    cout << "1. Aggiungi persona" << endl;
    cout << "2. Servi persona" << endl;
    cout << "Inserisci scelta: ";
}

void stampaMenu1(EliminaCoda e) {
    system("cls");
    e.stampaCode();
    cout << "---------" << endl << endl << "Menu Nuova Persona" << endl; 
    cout << "0. Indietro" << endl;
    cout << "1. Farmacia Medicinali" << endl;
    cout << "2. Sospesi Precedenza" << endl;
    cout << "3. Cosmetici e Integratori" << endl;
    cout << "Inserisci scelta: ";
}

void stampaMenu2(EliminaCoda e) {
    system("cls");
    e.stampaCode();
    cout << "---------" << endl << endl << "Menu Servi Persona" << endl; 
    cout << "0. Indietro" << endl;
    cout << "1. Farmacia" << endl;
    cout << "2. Cosmetici" << endl;
    cout << "Inserisci scelta: ";
}

int main() {

    EliminaCoda e(3, 2);

    string bho;
    int scelta;
    bool run = true; 
    do {
        stampaMenuPrincipale(e);
        cin >> scelta;
        
        switch (scelta) {
        case 0:
            run = false;
            break;
        case 1:
            scelta = -1;
            do {
                stampaMenu1(e);
                cin >> scelta;
                switch (scelta) {
                case 0:
                    break;
                case 1:
                    e.aggiungiPersona(FM);
                    break;
                case 2:
                    e.aggiungiPersona(SP);
                    break;
                case 3: 
                    e.aggiungiPersona(CI);
                    break;
                default:
                    cerr << "Scelta non valida, premere un tasto per proseguire ";
                    _getch();
                    break;
                }
            } while(scelta != 0);
            break;
        case 2:
            scelta = -1;
            do {
                stampaMenu2(e);
                cin >> scelta;
                int ncass;
                cout << "Inserisci numero cassa: ";
                cin >> ncass;
                switch (scelta) {
                case 0:
                    break;
                case 1:
                    try {e.serviPersona("Farmacia", ncass);}
                    catch(const std::out_of_range& e) {
                        cout << e.what() << ", premere un tasto per proseguire ";
                        _getch();

                    }
                    break;
                case 2:
                    try {e.serviPersona("Cosmetici", ncass);}
                    catch(const std::out_of_range& e) {
                        cout << e.what() << ", premere un tasto per proseguire ";
                        _getch();
                    }
                    break;
                default:
                    cerr << "Scelta non valida, premere un tasto per proseguire ";
                    _getch();
                    break;
                }
            }while(scelta != 0);
            break;
        default:
            cerr << "Scelta non valida, premere un tasto per proseguire ";
            _getch();
            break;
        }

    } while (run);
    
	return 0;
}