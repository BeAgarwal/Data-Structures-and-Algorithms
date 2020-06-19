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

void diagonalView(Node *node) {
    if (node == NULL)
        return;

    queue<Node *> q;
    map<int, vector<int> > m;
    q.push(node);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        int h = temp->hd;

        m[h].push_back(temp->info);
        if (temp->left) {
            temp->left->hd = h + 1;
            q.push(temp->left);
        }
        if (temp->right) {
            temp->right->hd = h;
            q.push(temp->right);
        }
    }

    for (auto itr = m.begin(); itr != m.end(); itr++) {
        for (int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i] << " ";
        } cout << endl;
    }
}

int main() {

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left->left = newNode(7);
    root->left->right->left->right = newNode(10);
    root->left->right->right = newNode(8);
    root->right->right = newNode(9);
    inorder(root);
    cout << endl;
    diagonalView(root);

    return 0;
}
/*  OUTPUT

2 7 6 10 5 8 1 3 9 
1 3 9 
2 5 8 
6 10 
7 

*/
