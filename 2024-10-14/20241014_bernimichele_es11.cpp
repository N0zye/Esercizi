#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main() {
	list<int> numbers;
	string input;
	do{
		cout << "Inserisci un numero oppure una stringa per terminare l'inserimento dati: ";
		cin >> input;
		try {
			int num = stoi(input);
			num%2==0?numbers.push_front(num):numbers.push_back(num);
		}catch(exception& idcAbtTheExcp) {
			input = "*";
		}
	}while(input != "*");
	cout << "Stampa dei numeri senza ordine: " << endl;
	for(int n :numbers) {
		cout << n << " ";
	}
	numbers.sort();
	cout << endl << "Stampa dei numeri in ordine crescente: " << endl;
	for(int n :numbers) {
		cout << n << " ";
	}
	
	return 0;
}