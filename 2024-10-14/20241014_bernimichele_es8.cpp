#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	vector<string> parole;
	string input;
	do{
		cout << "Inserisci parola o \"*\" per terminare l'inserimento dati: ";
		cin >> input;
		parole.push_back(input);
	}while(input != "*");
	parole.pop_back();
	
	cout << "Numero parole: " << to_string(parole.size()) << endl;
	
	parole.clear();
	
	cout << "Numero parole: " << to_string(parole.size());

	return 0;
}
