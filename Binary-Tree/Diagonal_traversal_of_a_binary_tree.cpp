#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void diagonalPrint(Node* root)
{
	queue<Node*>q;
    if(root == NULL) return;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        while(temp)
        {
            if(temp->left) q.push(temp->left);
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	
	diagonalPrint(root);
	return 0;
}