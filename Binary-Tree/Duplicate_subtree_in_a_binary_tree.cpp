// C++ program to find if there is a duplicate 
// sub-tree of size 2 or more. 
#include<bits/stdc++.h> 
using namespace std; 

const char MARKER = '$'; 

struct Node 
{ 
    char data; 
    Node *left, *right; 
}; 

Node* newNode(char data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

unordered_map<string, int> m; 

string solve(Node *root)
{
    if(!root) return "$";
    string s = "";
    if(!root->right && !root->left)
    {
        s = s + to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + solve(root->left);
    s = s + solve(root->right);
    m[s]++;
    return s;
}

bool dupSubUtil(Node *root) 
{ 
    m.clear();
    solve(root);
    for(auto i : m)
    {
        if(i.second >= 2) return true;
    }
    return false;
} 

int main() 
{ 
    Node *root = newNode('A'); 
    root->left = newNode('B'); 
    root->right = newNode('C'); 
    root->left->left = newNode('D'); 
    root->left->right = newNode('E'); 
    root->right->right = newNode('B'); 
    root->right->right->right = newNode('E'); 
    root->right->right->left= newNode('D'); 

    bool str = dupSubUtil(root); 

    if(str)
        cout<<"true";
    else
    {
        cout<<"flase";
    }
    return 0; 
} 
