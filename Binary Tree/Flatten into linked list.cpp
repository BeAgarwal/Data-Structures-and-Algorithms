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
void flatten(Node* root)
{
    if (root == NULL || root->left == NULL &&
            root->right == NULL) {
        return;
    }

    if (root->left != NULL) {

        flatten(root->left);

        Node* tmpRight = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }

        t->right = tmpRight;
    }

    flatten(root->right);
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
    flatten(root);
    cout << endl;
    inorder(root);
    return 0;
}
/*OUTPUT

4 2 5 1 6 3 7 
1 2 4 5 3 6 7 
*/
