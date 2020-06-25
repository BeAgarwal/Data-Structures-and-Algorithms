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

int ceil(Node *node, int x) {
    int res;
    while (node != NULL) {
        if (node->info == x)
            return node->info;
        else if (node->info > x) {
            res = node->info;
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return res;
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
    cout << endl << ceil(root, 5);  //  7
    return 0;

}
