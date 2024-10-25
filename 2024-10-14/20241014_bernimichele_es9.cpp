#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> nums;
	int num;
	for(int i=0;i<20;i++){
		cout << "Inserisci numero: ";
		cin >> num;
		nums.push_back(num);
	}
	
	for(vector<int>::iterator it = nums.end()-1; it>nums.end()-5; it--) {
		cout << *it << " ";
	}
	
	return 0;
}
