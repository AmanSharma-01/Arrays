// C++ implementation of a O(n) time method for
// Zigzag order traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

void zizagtraversal(struct Node* root)
{
    queue<struct Node*> q;
    if(!root) return;
    q.push(root);
    int f=1;
    while(!q.empty())
    {
        vector<int> temp;
        int s = q.size();
        while(s--)
        {
            struct Node* t = q.front();
            temp.push_back(t->data);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(f%2 == 0) reverse(temp.begin(), temp.end());
        for(int i=0;i<temp.size(); i++) cout<<temp[i]<<" ";
        f=!f;
    }
}

struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main()
{
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    zizagtraversal(root);

    return 0;
}