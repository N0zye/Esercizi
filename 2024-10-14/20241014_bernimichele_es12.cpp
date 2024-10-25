#include <iostream>
#include <ctime>
#include <map>

using namespace std;

int main() {

	time_t current_time = time(0);
	tm* local_tm = localtime(&current_time);
	int anno = (int)local_tm->tm_year + 1900;
	int nOccupati;
	map<int, int> anno_nOccupati;
	for(int i=anno-10;i<=anno;i++){
		cout << "Inserisci il numero di occupati per l'anno " << i << " : ";
		cin >> nOccupati;
		anno_nOccupati[i] = nOccupati;
	}
	int sum = 0;
	
	for(pair<int, int> p : anno_nOccupati) {
		sum += p.second;
	}
	
	cout << "Media degli occupati negli ultimi 10 anni = " << sum/anno_nOccupati.size() << endl;
	
	return 0;
}
