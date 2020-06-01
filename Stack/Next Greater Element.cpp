#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {100, 80, 160, 110, 20, 90, 30, 10, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    stack<int> S;

    S.push(arr[n - 1]);
    ans.push_back(-1);

    for (int i = n - 2; i >= 0; i--) {
        while (!S.empty() and S.top() <= arr[i]) {
            S.pop();
        }
        ans.push_back((S.empty()) ? -1 : S.top());
        S.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
/*OUTPUT
100 80 160 110 20 90 30 10 25 
160 160 -1 -1 90 -1 -1 25 -1 
*/
