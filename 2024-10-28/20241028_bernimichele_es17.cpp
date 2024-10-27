#include <iostream>
#include <vector>
#include <algorithm> // std::lower_bound
#include <functional> // std::function

using namespace std;

int binarySearch(const vector<int>& v, int toFind) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (v[middle] == toFind) {
            return middle;
        }
        if (v[middle] < toFind) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v;

    auto insertSorted = [&v](int value) {
        std::vector<int>::iterator pos = std::lower_bound(v.begin(), v.end(), value);
        v.insert(pos, value);
    };

    string input;
	do{
		cout << "Inserisci un numero oppure una stringa per terminare l'inserimento dati: ";
		cin >> input;
		try {
			int num = stoi(input);
			insertSorted(num);
		}catch(exception& idcAbtTheExcp) {
			input = "*";
		}
	}while(input != "*");

    cout << "Insrisci un numero da cercare: ";
    int toFind;
    cin >> toFind;

    int index = binarySearch(v, toFind);
    cout << "Il numero " << toFind << (index != -1 ? " e' presente nel vettore" : " non e' presente nel vettore");
    return 0;
}