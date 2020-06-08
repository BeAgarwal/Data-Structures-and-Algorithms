#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

int height(Node *root) {
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
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
    root->right->right->left = newNode(35);

    /*
            15
           /  \
         10    25
        /  \     \
       70  40    60
                /
               35

    */
    cout << height(root);  //4
    return 0;
}
