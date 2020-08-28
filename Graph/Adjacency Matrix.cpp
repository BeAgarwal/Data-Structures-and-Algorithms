//Code written by Shubham Agarwal
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    bool **matrix;
public:
    Graph(int V);
    void addEdge(int x, int y) {
        matrix[x][y] = 1;       //Directed
        // matrix[y][x] = 1;    //Undirected
    }
    void printMatrix(int m, int n);
};

Graph::Graph(int V) {
    this->V = V;

    matrix = new bool*[V];

    for (int i = 0; i < V; i++) {
        matrix[i] = new bool[V];
        memset(matrix[i], 0, V * sizeof(bool));
    }
}

void Graph::printMatrix(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {

    int x, y, V;
    Graph gp(5);
    cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> x >> y;
        gp.addEdge(x, y);
    }
    gp.printMatrix(V, V);
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

0 0 1 0 0 
0 0 0 1 0 
0 1 0 0 1 
0 0 0 0 0 
0 1 0 0 0 


*/
