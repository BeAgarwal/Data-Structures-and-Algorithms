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
Node *getSuccessor(Node *curr) {
    curr = curr->right;
    while (curr != NULL and curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node *del(Node *root, int k) {
    if (root == NULL)
        return NULL;
    if (root->info > k)
        root->left = del(root->left, k);
    else if (root->info < k)
        root->right = del(root->right, k);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node *succ = getSuccessor(root);
            root->info = succ->info;
            root->right = del(root->right, succ->info);
        }
    } return root;
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
    del(root, 10);
    cout << endl;
    inOrder(root);


    return 0;

}
