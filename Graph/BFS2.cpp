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
    void BFS(int s);
};

void Graph::BFS(int s) {
    queue<int> q;
    bool visited[V];
    memset(visited, false, sizeof(visited));
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int v : l[current]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main() {

    int x, y;
    Graph gp(5);
    for (int i = 0; i < 6; i++) {
        cin >> x >> y;
        gp.addEdge(x, y);
    }
    gp.BFS(0);
    return 0;
}
/* INPUT
0 2
2 1
2 4
4 1
1 3

OUTPUT

0 2 1 4 3


*/
