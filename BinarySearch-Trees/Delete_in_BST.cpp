// C++ program to implement optimized delete in BST.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

Node* insert(Node* node, int data)
{
	if (node == NULL)
		return newNode(data);

	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

Node* deleteNode(Node* root, int k)
{
	if(root == NULL)
        return root;

    if(root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if(root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }

    if(root->left == NULL)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {
        Node *succParent = root;
        Node *succ = root->right;

        while(succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if(succParent != root)
            succParent->left = succ->right;
        else 
            succParent->right = succ->right;

        root->data = succ->data;
        delete succ;
        return root;
    }

}


int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	Node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	printf("Inorder traversal of the given tree \n");
	inorder(root);

	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	return 0;
}
