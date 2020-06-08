/*Problem Statement

Given a 32 bit number x, reverse its binary form and print the answer in decimal.
Input:
2
1
5
Output:
2147483648
2684354560

Explanation:
Testcase1:
00000000000000000000000000000001 =1
10000000000000000000000000000000 =2147483648

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    long long n;
	    cin >> n;
	    long long r;
	    int i=0;
	    long long result=0;
	    while(i<32){
	        r=n%2;
	        n=n/2;
	        result=(result*2+r);
	        ++i;
	    }
	    cout << result << endl;
	}
	return 0;
}
