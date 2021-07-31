// C++ program of above approach
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		
	}
};


vector<int> largestBSTUtil(node* root)
{
    if(!root) return {1,0,INT_MAX,INT_MIN};
    if(!root->left && !root->right) return {1,1,root->data, root->data};

    vector<int> l = largestBSTUtil(root->left);
    vector<int> r = largestBSTUtil(root->right);

    if(l[0] && r[0])
    {
        if(root->data > l[3] && root->data < r[2])
        {
            int x = l[2];
            int y = r[3];
            if(x == INT_MAX) x = root->data;
            if(y == INT_MIN) y = root->data;
            return {1,l[1] + r[1] + 1, x, y};
        }
    }
    return {0,max(l[1], r[1]), 0,0};
}

int largestBST(node* node)
{
    vector<int> ans = largestBSTUtil(node);
    return ans[1];
}



int main()
{
	node *root = new node(50);
	root->left = new node(10);
	root->right = new node(60);
	root->left->left = new node(5);
	root->left->right = new node(20);
	root->right->left = new node(55);
	root->right->left->left = new node(45);
	root->right->right = new node(70);
	root->right->right->left = new node(65);
	root->right->right->right = new node(80);
	
	cout<<" Size of the largest BST is "<< largestBST(root);

	return 0;
}