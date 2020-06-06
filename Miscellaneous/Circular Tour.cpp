/*Code is written by Shubham Agarwal*/

#include<bits/stdc++.h>
using namespace std;

/* let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs 
    as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where the truck can make a circular tour is 2nd petrol pump.*/
    
int tour(int petrol[], int distance[], int n)
{
    int start = 0, sum = 0, diff = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + petrol[i] - distance[i];
        if (sum < 0) {
            start = i + 1;
            diff = diff + sum;
            sum = 0;
        }
    }
    return (((sum + diff) > 0) ? start : -1);
}

int main() {

    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};
    int n = sizeof(petrol) / sizeof(petrol[0]);
    cout << tour(petrol, distance, n);
    return 0;
}

