#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    string input;
	do{
		cout << "Inserisci un numero oppure una stringa per terminare l'inserimento dati: ";
		cin >> input;
		try {
			int num = stoi(input);
			v.push_back(num);
		}catch(exception& idcAbtTheExcp) {
			input = "*";
		}
	}while(input != "*");

    vector<int> vDoubleTriple;

    for (int n : v) {
        vDoubleTriple.push_back((n<100? n * 2 : n * 3));
    }

    cout << "Vettore moltiplicato: ";
    for (int n : vDoubleTriple) {
        cout << n << " ";
    }

    return 0;
}