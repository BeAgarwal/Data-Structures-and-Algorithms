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

void levelorder(Node *root) {
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *current = q.front();
        cout << current->info << " ";
        q.pop();
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
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
    levelorder(root);   //20 15 30 14 18 25 45
    return 0;
}
