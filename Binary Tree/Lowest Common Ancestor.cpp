//Code written by Shubham Agarwal

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int info;
    Node *left = NULL;
    Node *right = NULL;
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

Node *LCA(Node *node, int n1, int n2, bool &v1, bool &v2) {
    if (node == NULL)
        return NULL;

    if (node->info == n1) {
        v1 = true;
        return node;
    }
    if (node->info == n2) {
        v2 = true;
        return node;
    }

    Node *leftLCA = LCA(node->left, n1, n2, v1, v2);
    Node *rightLCA = LCA(node->right, n1, n2, v1, v2);

    if (leftLCA and rightLCA)
        return node;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

Node *findLCA(Node *node, int n1, int n2) {
    bool v1 = false;
    bool v2 = false;

    Node *lca = LCA(node, n1, n2, v1, v2);

    if (v1 and v2)
        return lca;
    else
        return NULL;
}
int main() {

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    inorder(root);
    cout << endl;

    Node *ans = new Node();
    ans = findLCA(root, 4, 5);
    if (ans == NULL)
        cout << "-1" << endl;
    else
        cout << ans->info << endl;

    ans = findLCA(root, 1, 11);
    if (ans == NULL)
        cout << "-1" << endl;
    else
        cout << ans->info << endl;

    ans = findLCA(root, 4, 7);
    if (ans == NULL)
        cout << "-1" << endl;
    else
        cout << ans->info << endl;

    ans = findLCA(root, 23, 13);
    if (ans == NULL)
        cout << "-1" << endl;
    else
        cout << ans->info << endl;

    return 0;
}
/*  OUTPUT
4 2 5 1 6 3 7 
2
-1
1
-1


*/
