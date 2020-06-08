#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

int getSize(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + getSize(root->left) + getSize(root->right);
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
    root->left->left = newNode(35);
    root->left->right = newNode(40);
    root->right->right = newNode(70);

    /*
            15
           /  \
         10    25
        /  \     \
       35  40    70

    */
    cout << getSize(root);  //6
    return 0;
}
