// C++ program to populate inorder
// traversal of all nodes
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left;
	node *right;
	node *next;
};

void populateNext(node* root)
{
    static node* nt = NULL;

    if(root)
    {
        populateNext(root->right);
        root->next = nt;
        nt = root;
        populateNext(root->left);
    }
}

node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	Node->next = NULL;

	return(Node);
}

int main()
{
	node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(12);
	root->left->left = newnode(3);
	root->left->left->right = newnode(4);
	root->left->left->left = newnode(2);

	populateNext(root);
	node *ptr = root->left->left->left;
	while(ptr)
	{
		cout << "Next of " << ptr->data << " is "
			<< (ptr->next? ptr->next->data: -1)
			<< endl;
		ptr = ptr->next;
	}

	return 0;
}