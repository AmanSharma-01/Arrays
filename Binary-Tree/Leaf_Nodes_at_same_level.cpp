// C++ program to check if all leaves
// are at same level
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
int ans;

void solve(struct Node *root, int h, int &prev_h)
{
    if(!root) return;
    if(ans==0) return;
    if(!root->left && !root->right)
    {
        if(h ==-1)
        {
            prev_h = h;
        }
        else
        {
            if(prev_h != h)
            {
                ans=0;
            }
        }
        return;
    }
    solve(root->left,h+1,prev_h);
    solve(root->right,h+1,prev_h);
}

bool check(struct Node *root)
{
    int h=0;
    int prev_h = -1;
    int ans=1;
    solve(root,h,prev_h);
    return ans;
}

int main()
{
	struct Node *root = newNode(12);
	root->left = newNode(5);
	root->left->left = newNode(3);
	root->left->right = newNode(9);
	root->left->left->left = newNode(1);
	root->left->right->left = newNode(1);
	if (check(root))
		cout << "Leaves are at same level\n";
	else
		cout << "Leaves are not at same level\n";
	return 0;
}