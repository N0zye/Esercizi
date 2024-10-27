#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    
    vector<string> comuni;

    string input;
    do {
        cout << "Inserisci un comune (oppure \"*\" per terminare l'inserimento): ";
        cin >> input;
        comuni.push_back(input);
    } while (input != "*");
    comuni.pop_back();

    unordered_map<string, int> comuniCount;
    for (string comune : comuni) {
        comuniCount[comune]++;
    }

    cout << "Inserisci comune per cercare il numero di occorrenze: ";
    cin >> input;
    int numOccorrenze;
    try {
        numOccorrenze = comuniCount.at(input);
    } catch (out_of_range& oor) {
        numOccorrenze = 0;
    }
    cout << "Il comune " << input << " e' presente " << numOccorrenze << " volte";

    return 0;
}