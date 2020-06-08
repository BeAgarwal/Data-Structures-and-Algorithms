#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

void kthNode(Node *root, int k) {
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << " ";
    else {
        kthNode(root->left, k - 1);
        kthNode(root->right, k - 1);
    }
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
    kthNode(root, 2);  //70 40 60
    return 0;
}
