//Code written by Shubham Agarwal
/*  INPUT
10
8 2 5 1 4 5 3 9 6 10
4
3 7
7 9
1 5
0 5
*/

#include<bits/stdc++.h>
using namespace std;

int a[100005], seg[4 * 10005];

void build(int index, int low, int high) {

    if (low == high) {
        seg[index] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);

    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
}

int query(int index, int low, int high, int l, int r) {
    if (low >= l and high <= r)
        return seg[index];
    if (high<l or low>r)
        return INT_MIN;
    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return max(left, right);
}

int main() {

    int n;  //number of elements in an array
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    int q;  //number of queries
    cin >> q;
    while (q--) {
        int l, r;   //left right
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << endl;
    }
    return 0;
}

/*  OUTPUT
9
10
5
8
*/

