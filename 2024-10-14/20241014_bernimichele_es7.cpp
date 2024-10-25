#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	vector<string> targhe;
	string input;
	do{
		cout << "Inserisci targa o \"*\" per terminare l'inserimento dati: ";
		cin >> input;
		targhe.push_back(input);
	}while(input != "*");
	targhe.pop_back();
	
	cout << "Stampa tutte le targhe: " <<endl;
	for(int i=0;i<(int)targhe.size();i++){
		cout << targhe.at(i) << " ";
	}
	cout << endl << "Stampa terzo elemento: ";
	try {
		cout << targhe.at(2);
	}catch (const out_of_range& oor) {
		cout << "Non ci sono elementi a sufficienza" << endl;
	}
	
	return 0;
}
