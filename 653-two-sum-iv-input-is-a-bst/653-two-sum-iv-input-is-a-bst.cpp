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

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse = false;
    
    void pushAll(TreeNode* node, bool rev) {
        if(rev) {
            for(;node!=NULL;node=node->right){
                st.push(node);
            }
        } else {
            for(;node!=NULL;node=node->left){
                st.push(node);
            }
        }
    }
    
public:
    BSTIterator(TreeNode* root, bool rev) {
        pushAll(root, rev);
        reverse = rev;
    }
    
    int next() {
        TreeNode* temp = st.top();st.pop();
        if(!reverse) pushAll(temp->right, reverse);
        else pushAll(temp->left, reverse);
        return temp->val;
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i<j) {
            if(i+j == k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};








