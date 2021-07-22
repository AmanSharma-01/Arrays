// Recursive optimized C++ program to find the diameter of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data);

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct node* node);

int m;

int func(struct node* root)
{
   if(!root) return 0;
   int x = func(root->left);
   int y = func(root->right);

   m = max(m, (x+y+1));
   return max(x,y)+1;
}

int diameter(struct node* root) 
{
    m=INT_MIN;
    int z = func(root);
    return m;
}

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Diameter of the given binary tree is " <<
        diameter(root);

    return 0;
}