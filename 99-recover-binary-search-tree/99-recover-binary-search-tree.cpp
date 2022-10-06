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
class Solution {
public:
    vector<int> ans;
    int idx;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    void inorder2(TreeNode* root) {
        if(!root) return;
        inorder2(root->left);
        root->val = ans[idx++];
        inorder2(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        idx=0;
        sort(ans.begin(), ans.end());
        inorder2(root);
    }
};