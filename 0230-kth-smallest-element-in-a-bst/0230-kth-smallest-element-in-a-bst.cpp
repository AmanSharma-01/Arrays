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
    void pushAll(TreeNode* root) {
        for(;root!=NULL;root=root->left) {
            st.push(root);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        BSTIterator *it = new BSTIterator(root);
        int ans = it->next();
        k--;
        while(k>0) {
            ans = it->next();
            k--;
        }
        return ans;
    }
};










