/*Code is written by Shubham Agarwal.*/

#include<bits/stdc++.h>
using namespace std;

int MaximumAreaHistogram(vector<int> arr, int n) {
    vector<int> left, right, width, area;
    stack<pair<int, int> >S, S2;

    for (int i = 0; i < n; i++) {
        while (!S.empty() and S.top().first >= arr[i]) {
            S.pop();
        }
        left.push_back((S.empty()) ? -1 : S.top().second);
        S.push({arr[i], i});
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!S2.empty() and S2.top().first >= arr[i]) {
            S2.pop();
        }
        right.push_back((S2.empty()) ? n : S2.top().second);
        S2.push({arr[i], i});
    }

    reverse(right.begin(), right.end());

    for (int i = 0; i < n; i++) {
        width.push_back(right[i] - left[i] - 1);
    }
    for (int i = 0; i < n; i++) {
        area.push_back(width[i] * arr[i]);
    }

    auto it = *max_element(area.begin(), area.end());
    return it;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(int);
    vector<int> v;

    for (int j = 0; j < m; j++) {
        v.push_back(arr[0][j]);
    }
    int result = MaximumAreaHistogram(v, v.size());
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                v[j] = 0;
            }
            else {
                v[j] = v[j] + arr[i][j];
            }
        }
        result = max(result, MaximumAreaHistogram(v, v.size()));
    }
    cout << result;
    return 0;
}
