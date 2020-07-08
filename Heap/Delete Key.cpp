//Code written by Shubham Agarwal
#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    int *arr;
    int size;
    int capacity;
public:
    MinHeap(int capacity);
    int left(int i) {
        return (2 * i + 1);
    }
    int right(int i) {
        return (2 * i + 2);
    }
    int parent(int i) {
        return ((i - 1) / 2);
    }
    void insert(int key);
    void minHeapify(int );
    int extractMin();
    void decreaseKey(int , int);
    void deleteKey(int );
    void display();
};
MinHeap::MinHeap(int c) {
    arr = new int[c];
    size = 0;
    capacity = c;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void MinHeap::insert(int key) {
    if (size == capacity) {
        cout << "Overflow";
        return;
    }
    size++;
    int i = size - 1;
    arr[i] = key;

    while (i != 0 and arr[i] < arr[parent(i)]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && arr[l] < arr[i])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(smallest);
    }
}
int MinHeap::extractMin()
{
    if (size <= 0)
        return INT_MAX;
    if (size == 1)
    {
        size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(0);

    return root;
}
void MinHeap::decreaseKey(int i, int key)
{
    arr[i] = key;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
void MinHeap::display() {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {

    MinHeap mh(10);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(40);
    mh.insert(50);
    mh.insert(100);
    mh.insert(25);
    mh.insert(45);
    mh.display();   //10 20 15 40 50 100 25 45
    mh.insert(12);
    mh.display();   //10 12 15 20 50 100 25 45 40
    mh.decreaseKey(3, 90);
    mh.display();   //10 12 15 90 50 100 25 45 40
    mh.deleteKey(0);
    mh.display();   //12 40 15 90 50 100 25 45 
    
    return 0;
}
