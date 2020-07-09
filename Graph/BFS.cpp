//Code written by Shubham Agarwal
#include<bits/stdc++.h>
using namespace std;

vector<int> v[5];
bool visited[5] = {0};

/*INPUT

5 5
0 2
2 1
2 4
4 1
1 3

*/
void bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < v[current].size(); i++) {
            int child = v[current][i];
            if (visited[child] == 0) {
                q.push(child);
                visited[child] = 1;
            }
        }
    }
}

void displayEdges(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int node, edge, x, y;
    cin >> node >> edge;
    for (int i = 1; i <= edge; i++) {
        cin >> x >> y;
        v[x].emplace_back(y);
    }
    displayEdges(node);
    bfs(0);
    return 0;
}

/* OUTPUT

0 -> 2 
1 -> 3 
2 -> 1 4 
3 -> 
4 -> 1 
0 2 1 4 3 


*/
