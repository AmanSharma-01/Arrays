/* C++ Program to find distance between n1 and n2
using one traversal */
#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int data;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}
Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(!root) return NULL;
       if(root->data == n1 || root->data == n2) return root;
       
       Node * l = lca(root->left, n1,n2);
       Node * r = lca(root->right, n1,n2);
       
       if(l && r) return root;
       if(l) return l;
       else return r;
    }
    
    int solve(Node * root,int val)
    {
        if(!root) return 0;
        if(root->data == val) return 1;
        
        int a = solve(root->left, val);
        int b = solve(root->right, val);
        
        if(!a && !b) return 0;
        else return a+b+1;
    }
    
int findDist(Node* root, int a, int b) {
    // Your code here
    Node * LCA = lca(root,a,b);
    int x = solve(LCA, a);
    int y = solve(LCA, b);
    return x+y-2;
}

int main()
{
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	cout << "Dist(4, 5) = " << findDist(root, 4, 5);
	cout << "\nDist(4, 6) = " << findDist(root, 4, 6);
	cout << "\nDist(3, 4) = " << findDist(root, 3, 4);
	cout << "\nDist(2, 4) = " << findDist(root, 2, 4);
	cout << "\nDist(8, 5) = " << findDist(root, 8, 5);
	return 0;
}
