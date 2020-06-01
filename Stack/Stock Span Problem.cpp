#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {100, 80, 60, 110, 20, 90, 30, 150, 25};
    /*             1   1    1   4   1   2   1   8   1*/
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans[n];
    stack<int> S;
    S.push(0);
    ans[0] = 1;
    for (int i = 1; i < n; i++) {
        while (!S.empty() and arr[S.top()] <= arr[i]) {
            S.pop();
        }
        ans[i] = (S.empty()) ? (i + 1) : (i - S.top());
        S.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
