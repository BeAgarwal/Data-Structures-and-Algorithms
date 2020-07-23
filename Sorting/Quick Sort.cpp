#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high + 1;
    while (i < j) {
        do {
            i++;
        } while (arr[i] <= pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[1000], n, T, i;
    cin >> T;
    while (T--) {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        quickSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
