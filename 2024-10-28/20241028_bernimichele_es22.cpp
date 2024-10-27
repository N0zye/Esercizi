#include <iostream>
#include <algorithm> // std::sort
#include <vector>
#include <set>

using namespace std;

int main() {

    vector<double> voti(5);
    for (int i = 0; i < 5; i++) {
        cout << "Inserisci il voto dello studente " << i + 1 << ": ";
        cin >> voti[i];
    }
    set<double> votiSet(voti.begin(), voti.end());

    cout << "I voti degli studenti senza duplicati sono: ";
    for (double voto: votiSet) {
        cout << voto << " ";
    }

    return 0;
}