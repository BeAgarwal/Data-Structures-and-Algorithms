#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int info;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node *insert(Node *root, int data) {
    if (root == NULL) {
        root = new Node;
        root->info = data;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        if (data < (root->info)) {
            root->left = insert(root->left, data);
        }
        if (data > (root->info)) {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

int main() {

    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 45);
    root = insert(root, 25);
    root = insert(root, 18);
    root = insert(root, 14);

    /*
             20
           /    \
         15      30
        /  \    /   \
      14   18  25   45

      */
    inorder(root); //14 15 18 20 25 30 45
    return 0;
}
