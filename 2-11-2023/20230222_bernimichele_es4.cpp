#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <unordered_map>

using namespace std;

/*4. Esercizio sulla classe Calcolatrice in C++:

Estendi la classe `Calcolatrice` floatroducendo la possibilità di memorizzare variabili e calcolare espressioni complesse. Aggiungi i seguenti metodi:

- `MemorizzaVariabile(string nomeVariabile, float valore)`: memorizza una variabile con un nome specifico e un valore.
- `RecuperaVariabile(string nomeVariabile)`: restituisce il valore memorizzato di una variabile specifica.
- `CalcolaEspressione(string espressione)`: calcola e restituisce il risultato di un'espressione matematica data, che può includere variabili precedentemente memorizzate e operazioni matematiche di base.
*/

class Calcolatrice {
private:
	unordered_map<string, float> memoria;
	bool precedenza(char operatore1, char operatore2) {
		unordered_map<char, int> precedenza = {
			{'+', 1},
        	{'-', 1},
        	{'*', 2},
        	{'/', 2},
        	{'^', 3}
		};
		return (precedenza[operatore1] >= precedenza[operatore2]);
	}
	float calcolaOperazione(float val1, char operartore, float val2) {
		float risultato = 0;
		switch (operartore)
		{
		case '+':
			risultato += somma(val1, val2);
			break;
		case '-':
			risultato += sottrazione(val1, val2);
			break;
		case '*':
			risultato += moltiplicazione(val1, val2);
			break;
		case '/':
			risultato += divisione(val1, val2);
			break;
		case '^':
			risultato += potenza(val1, val2);
			break;
		default:
			cerr << "Impossibile eseguire il calcolo, operatore " << operartore << " sconosciuto" << endl;
			break;
		}
		return risultato;
	}
public:
	float somma(float a, float b) {
		return a + b;
	}
	float sottrazione(float a, float b) {
		return a - b;
	}
	float moltiplicazione(float a, float b) {
		return a * b;
	}
	float divisione(float a, float b) {
		if (b != 0) {
			return a / b;
		}
		else {
			cout << "Impossibile dividere per 0" << endl;
			return -1;
		}
	}
	float radiceQuadrata(float numero) {
		return sqrt(numero);
	}
	float potenza(float base, float esponente) {
		float risultato = 1.0;
  		if (esponente < 0) {
    		base = 1.0 / base;
        	esponente = -esponente;
    	}
    	for (int i = 0; i < esponente; i++) {
    	    risultato *= base;
    	}
    	return risultato;
	}
	float fattoriale(float numero) {
		for (float i = 0; i < numero; i++) {
			numero *= numero - i;
		}
		return numero;
	}
	void memorizzaVariabile(string nomeVariabile, float valore) {
		memoria.emplace(nomeVariabile, valore);
	}
	float recuperaVariabile(string nomeVariabile) {
		float valore = 0.0;
    	try {
        	valore = memoria.at(nomeVariabile);
    	}
    	catch (const out_of_range& e) {
       		cerr << "Errore: Variabile " << nomeVariabile << " non trovata nella memoria." << endl;
    	}
    	return valore;
	}
	float calcolaEspressione(string espressione) { // val1 + val2 ^ 2 / 10 + 12 / 2
		float risultato = 0.0;
    	istringstream iss(espressione);
    	vector<string> sottostringhe;
    	vector<float> datiNumerici;
    	vector<char> operatori;

    	while (iss) {
        	string parola;
        	iss >> parola;
        	sottostringhe.push_back(parola);
   		}
   		if(!sottostringhe.empty()) {
   			sottostringhe.pop_back();
		}
    	for (string stringa : sottostringhe) {
        	try {
        	    datiNumerici.push_back(stof(stringa));
        	} catch (const invalid_argument& e) {
        	    if (stringa.size() > 1) {
        	    	datiNumerici.push_back(recuperaVariabile(stringa));
				}
				else {
					if (isalpha(stringa[0])) {
						datiNumerici.push_back(recuperaVariabile(stringa));
					}
					else {
						operatori.push_back(stringa[0]);
					}
				}
        	}
    	}
		while (!operatori.empty()) {
			for (int i = 0; i < operatori.size(); i++) {
				if (operatori.size() == 1) {
					datiNumerici[i] = calcolaOperazione(datiNumerici[i], operatori[i], datiNumerici[i+1]);
					operatori.erase(operatori.begin() + i);
					datiNumerici.erase(datiNumerici.begin() + i+1);
					break;
				}				
				else if (precedenza(operatori[i], operatori[i+1])) {
					datiNumerici[i] = calcolaOperazione(datiNumerici[i], operatori[i], datiNumerici[i+1]);
					operatori.erase(operatori.begin() + i);
					datiNumerici.erase(datiNumerici.begin() + i+1);
					break;
				}
			}
		}
		return datiNumerici[0];
	}
};

int main() 
{
	
	Calcolatrice c1;
	c1.memorizzaVariabile("addendo1", 10);
	cout << c1.calcolaEspressione("2 ^ 3 * 11 / 3 + 5 ^ 2 + addendo1");
	return 0;
}