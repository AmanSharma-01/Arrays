// C++ program check weather BST contains
// dead end or not
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node* insert(struct Node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	return node;
}

void storeNodes(Node * root, unordered_set<int> &all_nodes,unordered_set<int> &leaf_nodes)
{
	if(!root) return;

    all_nodes.insert(root->data);

    if(root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }

    storeNodes(root->left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

bool isDeadEnd(Node *root)
{
	if(!root) return NULL;
    unordered_set<int> all_nodes, leaf_nodes;
    storeNodes(root, all_nodes, leaf_nodes);

    for(auto i= leaf_nodes.begin() ; i != leaf_nodes.end(); i++ )
    {
        int x = (*i);
        if(all_nodes.find(x+1) != all_nodes.end() && all_nodes.find(x-1) != all_nodes.end())
            return true;
    }
    return false;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 7);
	root = insert(root, 11);
	root = insert(root, 4);
	if (isDeadEnd(root) == true)
		cout << "Yes " << endl;
	else
		cout << "No " << endl;
	return 0;
}
