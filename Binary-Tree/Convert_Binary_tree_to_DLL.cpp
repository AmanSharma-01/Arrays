// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

    void solve(node* root,node* &head,node* &prev,int &f)
    {
        if(!root) return;
        solve(root->left,head,prev,f);
        if(f==0)
        {
            head = root;
            prev = root;
            f=1;
        }
        else
        {
            prev->right = root;
            prev->right->left = prev;
            prev = prev->right;
        }
        solve(root->right,head,prev,f);
    }
    
    
    node * bToDLL(node *root)
    {
        node * head = NULL;
        node * prev = NULL;
        int f=0;
        solve(root,head,prev,f);
        return head;
    }

node* newNode(int data)
{
	node* new_node = new node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

void printList(node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->right;
	}
}

int main()
{
	node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	node* head = bToDLL(root);

	printList(head);

	return 0;
}