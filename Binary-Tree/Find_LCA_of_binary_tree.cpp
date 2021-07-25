/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int key;
};

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *findLCA(struct Node* root, int n1, int n2)
{
    if(!root) return NULL;
    if(root->key == n1 || root->key == n2) return root;

    struct Node* l = findLCA(root->left, n1,n2);
    struct Node* r = findLCA(root->right, n1,n2);

    if(l && r) return root;
    if(l) return l;
    else return r;
}

int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key<<"\n";
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->key<<"\n";
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->key<<"\n";
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->key<<"\n";
    return 0;
}