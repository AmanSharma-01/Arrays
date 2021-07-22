// C++ program to print top
// view of binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;
};

Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

void topview(Node* root)
{
	if(!root) return;
    map<int,int> m;
    queue<pair<Node*,int>>q;

    q.push({root, 0});
    while(!q.empty())
    {
        Node* temp = q.front().first;
        int h = q.front().second;
        q.pop();

        if(!m[h]) m[h]=temp->data;
        if(temp->left) q.push({temp->left,h-1});
        if(temp->right) q.push({temp->right,h+1});
    }

    for(auto i: m)
    {
        cout<<i.second<<" ";
    }

}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout << "Following are nodes in top view of Binary "
			"Tree\n";
	topview(root);
	return 0;
}