#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}

double maxValue(vector<pair<int, int>> array, int n, int capacity) {

    sort(array.begin(), array.end(), compare);

    // after sorting, the wight and value will be like
    // 20 500
    // 10 200
    // 30 400
    // 50 600
    // 5 50
    // 20 100

    double value = 0.0;
    for (int i = 0; i < n; ++i) {
        if (capacity > array[i].first) {
            value += array[i].second;
            capacity -= array[i].first;
        } else {
            value += array[i].second * ((double)capacity / (array[i].first * 1.0));
            break;
        }
    }
    return value;
}

int main() {

    vector<pair<int, int>> array = {
        {50, 600},
        {20, 500},
        {30, 400},
        {10, 200},
        {5, 50},
        {20, 100}
    };
    int n = sizeof(array) / sizeof(int);

    int capacity = 15;
    cout << maxValue(array, n, capacity);   //375
    return 0;
}