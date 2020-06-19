//Code written by SHubham Agarwal

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

void bottomView(Node *node) {
    if (node == NULL)
        return;

    queue<Node *> q;
    map<int, int> m;
    q.push(node);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        int h = temp->hd;

        m[h] = temp->info;

        if (temp->left) {
            temp->left->hd = h - 1;
            q.push(temp->left);
        }

        if (temp->right) {
            temp->right->hd = h + 1;
            q.push(temp->right);
        }

    }
    for (auto itr = m.begin(); itr != m.end(); itr++)
        cout << itr->second << " ";
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
    bottomView(root);

    return 0;
}
/*OUTPUT
2 7 6 5 8 1 3 9 
7 6 5 8 9 
*/
