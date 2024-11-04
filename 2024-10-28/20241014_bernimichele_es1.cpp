#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

void wow(vector<string>& help, int k, set<string>& womboCombo, string current = "") {
    if (k == 0) {
        womboCombo.insert(current);
        return;
    }

    for (int i = 0; i < help.size(); i++) {
        vector<string> temp = help;
        string newCurrent = current + " " + temp[i];
        temp.erase(temp.begin() + i);
        wow(temp, k - 1, womboCombo, newCurrent);
    }
    

}

set<string> combinazioniUnivoche(vector<string> parole, int k) {
    set<string> ps;
    wow(parole, k, ps);
    return ps;
}

int main() {
	
	vector<string> parole = {"ciao", "mamma", "come", "stai"};
	
	set<string> pls = combinazioniUnivoche(parole, 4);
	
	for(string aiudo:pls){
		cout << aiudo << endl;
	}
	
	return 0;
}
