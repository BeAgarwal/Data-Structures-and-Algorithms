#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {100, 80, 160, 110, 20, 90, 30, 10, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    stack<int> S;

    S.push(arr[0]);
    ans.push_back(-1);

    for (int i = 1; i < n; i++) {
        while (!S.empty() and S.top() <= arr[i]) {
            S.pop();
        }
        ans.push_back((S.empty()) ? -1 : S.top());
        S.push(arr[i]);
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
/*OUTPUT
100 80 160 110 20 90 30 10 25 
-1 100 -1 160 110 110 90 30 30 
*/
