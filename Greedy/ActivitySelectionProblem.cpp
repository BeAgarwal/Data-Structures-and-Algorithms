#include<bits/stdc++.h>
using namespace std;

bool compare (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int countActivity(vector<pair<int, int>> activity, int n) {

    sort(activity.begin(), activity.end(), compare);

    // after sort, activity will be like
    // 1 2, 3 4, 0 6, 5 7, 5 9, 8 9

    int count = 1;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (activity[i].first >= activity[j].second) {
            count++;
            j = i;
        }
    }

    return count;
}

int main() {

    vector<pair<int, int>> activity = {
        {5, 9},
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9}
    };
    int n = sizeof(activity) / sizeof(int);
    cout << countActivity(activity, n);     //4
    return 0;
}