#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Person {
private:
    string name;
public:
    Person(string name) : name(name){}
    string getname() const{
        return name;
    }
    bool operator<(const Person& other) const {
        return name > other.name; // Highest one is the last in alphabetical order, so reversed contition to get the first.
    }
};

int main() {

    priority_queue<Person> pq;

    pq.emplace("Andrew");
    pq.emplace("Charlie");
    pq.emplace("David");
    pq.emplace("Bob");

    while (!pq.empty())
    {
        cout << pq.top().getname() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
