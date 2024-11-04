#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>> tokenizeAndMapOcc(string s) {
    vector<pair<string, int>> occorrenze;
    string parola = "";

    for (char c : s) {
        if (c == ' ' || c == ',' || c == '.') {
            if (!parola.empty()) {
                bool found = false;
                for (auto& occ : occorrenze) {
                    if (occ.first == parola) {
                        occ.second++; 
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    occorrenze.push_back(make_pair(parola, 1));
                }
                parola = ""; 
            }
        } else {
            parola += tolower(c);
        }
    }

    if (!parola.empty()) { //L'ultima parola
        bool found = false;
        for (auto& occ : occorrenze) {
            if (occ.first == parola) {
                occ.second++;
                found = true;
                break;
            }
        }
        if (!found) {
            occorrenze.push_back(make_pair(parola, 1));
        }
    }

    return occorrenze;
}

bool customSort(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
            return a.first < b.first; // Ordine alfabetico se la frequenza è la stessa
    }
    return a.second > b.second; // Ordine decrescente di frequenza
}

int main() {


    string s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    vector<pair<string, int>> occorrenza= tokenizeAndMapOcc(s); // con la mappa non si puo fare il custom sort

    sort(occorrenza.begin(), occorrenza.end(), customSort);
     
    for (auto& occ : occorrenza) {
        cout << occ.first << " " << occ.second << endl;
    }

    return 0;
}