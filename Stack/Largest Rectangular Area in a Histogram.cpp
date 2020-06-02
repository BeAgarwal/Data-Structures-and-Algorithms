#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

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
    cout << "arr:\t";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\t';
    }
    cout << "\nleft:\t";
    for (int i = 0; i < n; i++) {
        cout << left[i] << '\t';
    }
    cout << "\nright:\t";
    for (int i = 0; i < n; i++) {
        cout << right[i] << '\t';
    }

    for (int i = 0; i < n; i++) {
        width.push_back(right[i] - left[i] - 1);
    }
    for (int i = 0; i < n; i++) {
        area.push_back(width[i] * arr[i]);
    }
    cout << "\nwidth:\t";
    for (int i = 0; i < n; i++) {
        cout << width[i] << '\t';
    }
    cout << "\narea:\t";
    for (int i = 0; i < n; i++) {
        cout << area[i] << '\t';
    }
    cout << endl << "max:\t" << *max_element(area.begin(), area.end());
    return 0;
}

/*OUTPUT
arr:	6	2	5	4	5	1	6	
left:	-1	-1	1	1	3	-1	5	
right:	1	5	3	5	5	7	7	
width:	1	5	1	3	1	7	1	
area:	6	10	5	12	5	7	6	
max:	12
*/
