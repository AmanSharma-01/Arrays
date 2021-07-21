// A C++ program to print REVERSE level order traversal using stack and queue
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void reverseLevelOrder(node* root)
{
	stack<node *> s;
    queue<node *> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        s.push(temp);

        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }

    while(!s.empty())
    {
        node *tem = s.top();
        cout<<tem->data<<" ";
        s.pop();
    }
}

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}

int main()
{
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}
