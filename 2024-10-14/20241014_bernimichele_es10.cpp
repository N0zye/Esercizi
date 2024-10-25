#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
void printContent(vector<T> v) {
	for(typename vector<T>::iterator it = v.begin();it != v.end();it++){
		cout << *it << " ";
	}
}

int main() {
	
	vector<string> reparti;
	vector<int> numAddetti;
	string reparto;
	int num;
	do{
		cout << "Inserisci nome reparto o \"*\" per terminare l'inserimento dati: ";
		cin >> reparto;
		reparti.push_back(reparto);
		cout << "Inserisci il numero di addetti al reparto " << reparto << " : ";
		cin >> num;
		numAddetti.push_back(num);
		
	}while (reparto != "*");
	
	reparti.pop_back();
	numAddetti.pop_back();
	
	cout << "Stampa reparti: " << endl;
	printContent(reparti);
	cout << endl << "Stampa addetti: " << endl;
	printContent(numAddetti);
	return 0;
}
