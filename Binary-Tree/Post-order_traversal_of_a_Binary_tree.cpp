#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 

void postorder(Node* root) // Recursive function to perform postorder traversal on the tree
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void postorderIterative(Node* root) // Iterative function to perform postorder traversal on the tree
{
    stack<Node*> s;
    s.push(root);
    stack<int> out;
 
    while (!s.empty())
    {
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);

        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }

    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
 
 
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    postorderIterative(root);
 
    return 0;
}