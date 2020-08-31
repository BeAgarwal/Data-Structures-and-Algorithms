/*

Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix.
Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& A, int x, int y, int m, int n)
{
    if (x < 0 or y < 0 or x >= m or y >= n or A[x][y] != 1)
        return;

    A[x][y] = 2;

    dfs(A, x + 1, y, m, n);
    dfs(A, x, y + 1, m, n);
    dfs(A, x - 1, y, m, n);
    dfs(A, x, y - 1, m, n);
    dfs(A, x + 1, y + 1, m, n);
    dfs(A, x - 1, y + 1, m, n);
    dfs(A, x + 1, y - 1, m, n);
    dfs(A, x - 1, y - 1, m, n);
}

int NumberofIsland(vector<vector<int>>& A, int m, int n)
{

    int num = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == 1) {
                dfs(A, i, j, n, m);
                num += 1;
            }
        }
    }
    return num;
}

int main()
{
    int N = 5, M = 8;

    vector<vector<int>> A;
    A = {
        { 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 0, 0, 1 },
        { 0, 1, 0, 1, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1 }
    };

    cout << NumberofIsland(A, M, N);  //2
    return 0;
}
