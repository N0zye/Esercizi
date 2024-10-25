#include <iostream>
#include "capitals.hpp"

using namespace std;

int main() {

    string input;
    do {
       cout << "Inserisci il nome di uno stato per conoscere la sua capitale (o \"*\" per uscire): ";
        getline(cin, input);
        try {
            cout << capitals.at(input) << endl;
        } catch(const out_of_range& oor) {
            if (input == "*") {
                break;
            }    
            cout << "Stato non trovato" << endl;
        }
         
    } while (input != "*");
    

    return 0;
}