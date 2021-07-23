#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
    int data;
    struct node *left, *right;
};

void LeftTree (struct node *root)
    {
        if(!root) return;
        if(root->left)
        {
            cout<<root->data<<" ";
            LeftTree(root->left);
        }
        else if(root->right)
        {
            cout<<root->data<<" ";
            LeftTree(root->right);
        }
    }
    
    void Leaf(struct node* root)
    {
        if(!root) return;
        Leaf(root->left);
        if(!root->left && !root->right) cout<<root->data<<" ";
        Leaf(root->right);
    }
    
    void RightTree(struct node *root)
    {
        if(!root) return;
        if(root->right)
        {
            RightTree(root->right);
            cout<<root->data<<" ";
        }
        else if(root->left)
        {
            RightTree(root->left);
            cout<<root->data<<" ";
        }
    }

    void printBoundary(struct node* root)
    {
        cout<<root->data<<" ";
        LeftTree(root->left);
        Leaf(root);
        RightTree(root->right);
    }

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

int main()
{
    struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}
