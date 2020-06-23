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

bool Search(Node *root, int k) {
    if (root == NULL)
        return false;
    if (root->info == k)
        return true;
    if (root->info > k)
        return Search(root->left, k);
    else
        return Search(root->right, k);
}

void inOrder(Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->info << " ";
    inOrder(root->right);
}

int main() {

    Node *root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(9);
    root->right = newNode(12);
    root->right->left = newNode(11);
    root->right->right = newNode(13);

    inOrder(root);
    cout << endl << Search(root, 9);    // 1
    cout << endl << Search(root, 14);   // 0


    return 0;

}
