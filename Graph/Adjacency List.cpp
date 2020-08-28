//Code written by Shubham Agarwal

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y) {
        l[x].emplace_back(y);
    }
    void displayEdges(int n);
};

void Graph::displayEdges(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto j : l[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {

    int x, y, V;
    cin >> V;
    Graph gp(V);
    for (int i = 0; i < V; i++) {
        cin >> x >> y;
        gp.addEdge(x, y);
    }
    gp.displayEdges(V);
    return 0;
}

/*
INPUT
5
0 2
2 1
2 4
4 1
1 3

OUTPUT

0 -> 2
1 -> 3
2 -> 1 4
3 ->
4 -> 1

*/
