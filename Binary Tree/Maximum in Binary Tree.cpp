#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

int maximum(Node *root) {
    if (root == NULL)
        return -1;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

Node *newNode(int info) {
    Node *temp = new Node;
    temp->left = NULL;
    temp->data = info;
    temp->right = NULL;
    return temp;
}

int main() {

    Node *root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(25);
    root->left->left = newNode(70);
    root->left->right = newNode(40);
    root->right->right = newNode(60);

    /*
            15
           /  \
         10    25
        /  \     \
       70  40    60

    */
    cout << maximum(root);  //70
    return 0;
}
