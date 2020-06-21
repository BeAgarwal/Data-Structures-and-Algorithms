//Code written by Shubham Agarwal

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int info;
    Node *left;
    Node *right;
};

Node *newNode(int data) {
    Node *temp = new Node;
    temp->left = NULL;
    temp->info = data;
    temp->right = NULL;
    return temp;
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    cout << root->info << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *convert(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *root = newNode(arr[mid]);

    root->left = convert(arr, start, mid - 1);
    root->right = convert(arr, mid + 1, end);

    return root;
}
int main() {

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = convert(arr, 0 , n - 1);

    preOrder(root); //10 4 2 6 8 16 12 14 18 20 

    return 0;

}
