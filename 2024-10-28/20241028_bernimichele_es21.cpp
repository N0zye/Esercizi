#include <iostream>
#include <algorithm> // std::sort
#include <vector>

using namespace std;

int main() {

    vector<double> tempi(10);
    double tempo;
    for (int i = 0; i < 10; i++) {
        cout << "Inserisci il tempo del " << i + 1 << "° concorrente: ";
        cin >> tempo;
        tempi[i] = tempo;
    }
    
    sort(tempi.begin(), tempi.end());

    vector <double> top3(3);
    for (int i = 0; i < 3; i++) {
        top3[i] = tempi[i];
    }

    cout << "I tempi dei primi tre concorrenti sono: ";
    for (double tempo: top3) {
        cout << tempo << " ";
    }

    return 0;
}