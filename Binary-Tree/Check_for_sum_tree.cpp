// C++ program to check if Binary tree
// is sum tree or not
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int f=1;

int solve(struct node* root)
{
    if(!root) return 0;
    if(!root->right && !root->left) return root->data;
    int l = solve(root->left);
    int r = solve(root->right);
    if(l+r != root->data) f=0;
    return l+r+root->data;
}

int isSumTree(struct node* node)
{
    f=1;
    solve(node);
    return f;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    
    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";

    return 0;
}