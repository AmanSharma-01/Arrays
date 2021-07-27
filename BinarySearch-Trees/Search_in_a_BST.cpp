// C++ program to demonstrate insertion in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Inorder(BST*);
    BST* Search(BST*,int);
};

BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
	if(!root)
    {
        return new BST(value);
    }

    if(value > root->data)
    {
        root->right = Insert(root->right,value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

BST* BST ::Search(BST* root,int key)
{
    if(!root) return root;
    if(root->data == key)
    {
        cout<<"data found";
        return root;
    }

    if(root->data < key)
    {
        return Search(root->right, key);
    }

    return Search(root->left, key);
}

void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
    BST* node = b.Search(root, 90);
	return 0;
}