#include <bits/stdc++.h>
using namespace std;

struct Node
{
Node* left;
Node* right;
int data;

Node(int element){
	data = element;
	this->left = nullptr;
	this->right = nullptr;
}
};

vector<int> solve(Node *root)
{
    if(!root) return {0,0};

    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);

    if(l[0]>r[0]) return {l[0]+1,l[1] + root->data};
    if(l[0]<r[0]) return {r[0]+1,r[1] + root->data};
    else return {r[0]+1, max(l[1],r[1])+ root->data};
}

int longestPathLeaf(Node* root)
{
    vector<int> ans = solve(root);
    return ans[1];
}

int main() {

Node* root = new Node(4);		
root->left = new Node(2);		
root->right = new Node(5);	
root->left->left = new Node(7);
root->left->right = new Node(1);
root->right->left = new Node(2);
root->right->right = new Node(3);
root->left->right->left = new Node(6);

cout << longestPathLeaf(root) << "\n";
	
return 0;
}
