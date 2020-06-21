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

void preOrder(Node *root) {
    if (root == NULL)
        return;
    cout << root->info << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node *convert(vector<Node *> v, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *root = v[mid];

    root->left = convert(v, start, mid - 1);
    root->right = convert(v, mid + 1, end);

    return root;
}
void convertIntoArray(Node *root, vector<Node *> &v) {
    if (root == NULL)
        return;
    convertIntoArray(root->left, v);
    v.push_back(root);
    convertIntoArray(root->right, v);

}
Node *buildTree(Node *root) {
    vector<Node *> v;
    convertIntoArray(root, v);
    int n = v.size();
    return convert(v, 0, n - 1);
}
int main() {

    Node *root = newNode(10);
    root->left = newNode(9);
    root->left->left = newNode(8);
    root->left->left->left = newNode(7);
    root->left->left->left->left = newNode(6);
    root->left->left->left->left->left = newNode(5);
    root->left->left->left->left->left->left = newNode(4);
    root->left->left->left->left->left->left->left = newNode(3);

    root = buildTree(root); //6 4 3 5 8 7 9 10
    preOrder(root);
    return 0;

}
