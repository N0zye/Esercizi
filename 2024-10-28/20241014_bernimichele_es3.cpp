#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class Graph {
private:
    unordered_map<T, vector<T>> adjList;
public:
    void addEdge(T from, T to, bool directed = true) {
        adjList[from].push_back(to);
        if (!directed) {
            adjList[to].push_back(from);
        } else { adjList[to]; } 
    }
    //Topologial sort using kahn's algorithm
    vector<T> topologicalSort() {
        vector<T> result;
        unordered_map<T, int> inDegree;
        for (pair<T, vector<T>> element : adjList) {
            inDegree[element.first] = 0;
        }
        for (pair<T, vector<T>> element : adjList) {
            for (T neighbour : element.second) {
                inDegree[neighbour]++;
            }
        }
        queue<T> q;
        for (pair<T, int> element : inDegree) {
            if (element.second == 0) {
                q.push(element.first);
            }
        }
        while (!q.empty()) {
            T node = q.front();
            q.pop();
            result.push_back(node);
            for (T neighbour : adjList[node]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return (result.size() == adjList.size()) ? result : vector<T>();
    }

};

int main() {

    Graph<string> g;
    g.addEdge("A", "B");
    g.addEdge("B", "C"); 
    g.addEdge("B", "D");
    g.addEdge("A", "F");
    g.addEdge("G", "F");

    vector<string> result = g.topologicalSort();
    if (result.size() == 0) {
        cout << "Graph is not a DAG" << endl;
    } else {
        for (string node : result) {
            cout << node << " ";
        }
    }

    return 0;
}