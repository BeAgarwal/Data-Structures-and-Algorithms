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

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " ";
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
    postorder(root); //14 18 15 25 45 30 20 
    return 0;
}
