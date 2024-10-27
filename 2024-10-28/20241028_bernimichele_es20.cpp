#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> mergeSort(vector<string>);
vector<string> merge(vector<string>, vector<string>);


int main() {
    
    vector<string> cognomi1A;
    vector<string> cognomi1B;
    string input;
    do {
        cout << "Inserisci i cognomi degli studenti di 1A(oppure \"*\" per terminare l'inserimento): ";
        cin >> input;
        input[0] = toupper(input[0]);
        cognomi1A.push_back(input);
    } while (input != "*");
    cognomi1A.pop_back();
    do {
        cout << "Inserisci i cognomi degli studenti di 1B(oppure \"*\" per terminare l'inserimento): ";
        cin >> input;
        input[0] = toupper(input[0]);
        cognomi1B.push_back(input);
    } while (input != "*");
    cognomi1B.pop_back();

    vector<string> cognomi1A1B = merge(mergeSort(cognomi1A), mergeSort(cognomi1B));

    cout << "Cognomi uniti e ordinati: ";
    for (string cognome: cognomi1A1B) {
        cout << cognome << " ";
    }

    return 0;
}

vector<string> mergeSort(vector<string> v) {
    if (v.size() == 1) {
        return v;
    }
    vector<string> left = vector<string>(v.begin(), v.begin() + v.size() / 2);
    vector<string> right = vector<string>(v.begin() + v.size() / 2, v.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

vector<string> merge(vector<string> left, vector<string> right) {
    vector<string> merged;
    
    while (left.size() > 0 && right.size() > 0) {
        if (left[0] < right[0]) {
            merged.push_back(left[0]);
            left.erase(left.begin());
        } else {
            merged.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while (left.size() > 0) {
        merged.push_back(left[0]);
        left.erase(left.begin());
    }
    while (right.size() > 0) {
        merged.push_back(right[0]);
        right.erase(right.begin());
    }
    
    return merged;
}