/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BST {
private:
    stack<TreeNode*> st;
    bool reverse;
    void pushAll(TreeNode* root, bool rev) {
        if(rev) {
            for(;root!=NULL;root=root->right) st.push(root);
        } else {
            for(;root!=NULL;root=root->left) st.push(root);
        }
    }
public:
    BST(TreeNode* root, bool rev) {
        pushAll(root, rev);
        reverse = rev;
    }
    
    int next() {
        TreeNode* temp = st.top();st.pop();
        if(reverse) pushAll(temp->left, reverse);
        else pushAll(temp->right, reverse);
        return temp->val;
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BST l(root, false);
        BST r(root, true);
        
       int i = l.next();
       int j = r.next();
        
        while(i<j) {
            if(i+j == k) return true;
            else if(i+j<k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};







