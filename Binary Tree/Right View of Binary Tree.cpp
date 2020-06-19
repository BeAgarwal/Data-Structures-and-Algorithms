//Code written by Shubham Agarwal

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int info;
    Node *left = NULL;
    Node *right = NULL;
    int hd;
};

Node *root = NULL;

Node *newNode(int data) {
    Node *temp = new Node;
    temp->info = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

void rightView(Node *node) {
    if (node == NULL)
        return;

    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
        int n = q.size();


        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();
            if (i == n - 1)
                cout << temp->info << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

}

int main() {

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left->left = newNode(7);
    root->left->right->right = newNode(8);
    root->right->right = newNode(9);
    inorder(root);
    cout << endl;
    rightView(root);  //1 3 9 8 7

    return 0;
}
