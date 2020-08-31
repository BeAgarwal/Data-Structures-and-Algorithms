/*

A closed island is known as the group of 1s that is surrounded by only 0s 
on all the four sides (excluding diagonals). If any 1 is at the edges of 
the given matrix then it is not considered as the part of the connected island 
as it is not surrounded by all 0. 

*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& A, int x, int y, int m, int n, vector<vector<bool>>& visited)
{
    if (x < 0 or y < 0 or x >= m or y >= n or A[x][y] == 0 or visited[x][y] == true)
        return;

    visited[x][y] = true;

    dfs(A, x + 1, y, m, n, visited);
    dfs(A, x, y + 1, m, n, visited);
    dfs(A, x - 1, y, m, n, visited);
    dfs(A, x, y - 1, m, n, visited);
}

int NumberofIsland(vector<vector<int>>& A, int m, int n)
{
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    int num = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            if ((i * j == 0 or i == m - 1 or j == n - 1) and A[i][j] == 1 and visited[i][j] == false)
                dfs(A, i, j, m, n, visited);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 1 and visited[i][j] == false) {
                dfs(A, i, j, m, n, visited);
                num += 1;
            }
        }
    }
    return num;
}

int main()
{
    int M = 5, N = 8;

    vector<vector<int>> A;
    A = {
        { 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 0, 0, 1 },
        { 1, 1, 0, 1, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1 }
    };

    cout << NumberofIsland(A, M, N);    //1
    return 0;
}
