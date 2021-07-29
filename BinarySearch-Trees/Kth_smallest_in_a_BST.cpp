// C++ program to find k'th largest element in BST
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;
};

Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void kthLargestUtil(Node *root, int k, int &c)
{
	if(!root || c < 0) return;

    kthLargestUtil(root->left, k, c);
    c--;
    if(c == 0)
    {
        cout<<k<<"'th smallest is "<< root->key;
        return;
    }
    kthLargestUtil(root->right, k, c);
}

void kthLargest(Node *root, int k)
{
	int c = k;

	kthLargestUtil(root, k, c);
}

Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	int c = 0;
		kthLargest(root, 4);

	return 0;
}
