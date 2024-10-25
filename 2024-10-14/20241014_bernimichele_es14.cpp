#include <iostream>
#include <map>
#include <conio.h> // getch()
#include <algorithm> // transform
#include <cctype>    // tolower

using namespace std;

class Nominativo {
private:
    string nome, cognome;
public:
    Nominativo(string nome, string cognome) : nome(nome), cognome(cognome) {}
    bool stringPartialCompare(string givenOne) {
        string a = nome + " " + cognome;
        string aInvverted = cognome + " " + nome;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(aInvverted.begin(), aInvverted.end(), aInvverted.begin(), ::tolower);
        transform(givenOne.begin(), givenOne.end(), givenOne.begin(), ::tolower); // the :: is the scope resolution operator
        // it's used to specify that the function to be called is the one defined in the global namespace (not any kind of local maybe custom namespace)
        return a.find(givenOne) != string::npos || aInvverted.find(givenOne) != string::npos;        
    }
    string getNome() { return nome; }
    string getCognome() { return cognome; }
    string getNomeCognome() { return nome + " " + cognome; }
};

class Rubrica {
private:
    map<string, Nominativo> rubrica;

    void nuovoContatto() {
        string nome, cognome, numero;
        system("cls");
        cout << "Inserisci il nome: ";
        cin >> nome;
        cout << "Inserisci il cognome: ";
        cin >> cognome;
        cout << "Inserisci il numero di telefono: ";
        cin >> numero;
        rubrica.insert(pair<string, Nominativo>(numero, Nominativo(nome, cognome)));
        cout << "Contatto inserito correttamente, premere un tasto per tornare al menu principale ";
        _getch();
        menuPrincipale();
    }

    void cercaContatto() {
        system("cls");
        char ch;
        string input;
        cout << "Scrivi il nome/cognome (premi Invio per terminare): ";
        cin.get(ch); // to clear the buffer
        while (true) {
            ch = _getch();
            if (ch == '\r')  // Check for Enter key (ASCII 13)
                break;
            if (ch == 8) {  // Handle Backspace (ASCII 8)
                if (!input.empty())
                    input.pop_back();
            } else {
                input += ch;
            }
            system("cls");
            std::cout << "Scrivi il nome/cognome (premi Invio per terminare): " << input << std::endl;
            stampaContattiPerStringa(input);
        }   
        cout << "Premere un tasto per tornare al menu principale ";
        _getch();
        menuPrincipale();
    }

    void visualizzaContatti() {
        system("cls");
        cout << "Contatti presenti nella rubrica: " << endl;
        for (auto it = rubrica.begin(); it != rubrica.end(); it++) {
            cout << it->second.getNomeCognome() << " - " << it->first << endl;
        }
        cout << "Premere un tasto per tornare al menu principale ";
        _getch();
        menuPrincipale();
    }

    void menuPrincipale() {
        system("cls");
        cout << "1. Inserisci un nuovo contatto" << endl;
        cout << "2. Cerca un contatto" << endl;
        cout << "3. Visualizza tutti i contatti" << endl;
        cout << "4. Esci" << endl;
        cout << "Scelta: ";
        int scelta;
        cin >> scelta;
        switch (scelta) {
        case 1:
            nuovoContatto();
            break;
        case 2:
            cercaContatto();
            break;
        case 3:
            visualizzaContatti();
            break;
        case 4:
            cout << "Arrivederci!" << endl;
            exit(0); // lo so non ha senso, ma piuttosto che avere la rubrica globale o passarla come parametro o peggio dei switch annidati...
            // a meno che io non la trasformi in un singleton, ma non mi sembra il caso
            break;
        default:
            cerr << "Scelta non valida, premere un tasto per proseguire ";
            _getch();        
            menuPrincipale();
            break;
        }
    }

    void stampaContattiPerStringa(string s) {
        for (auto it = rubrica.begin(); it != rubrica.end(); it++) {
            if (it->second.stringPartialCompare(s)) {
                cout << it->second.getNomeCognome() << " - " << it->first << endl;
            }
        }
    }

public:
    Rubrica() {
        menuPrincipale();
    }
};



int main() {

    Rubrica rubrica;
    
    return 0;
}