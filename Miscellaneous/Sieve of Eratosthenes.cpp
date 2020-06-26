//Code written by Shubham Agarwal


//Time complexity : O(n*log(log(n)))


#include<bits/stdc++.h>
using namespace std;

void Sieve(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j <= n; j = j + i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            cout << i << " ";
    }
}
int main() {

    Sieve(50);
    cout << endl;
    Sieve(100);
    return 0;
}

/* OUTPUT
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 
*/
