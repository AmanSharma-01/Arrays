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
    
    bool isValid(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left) return false;
        if(!right) return false;
        if(left->val != right->val) return false;
        
        return isValid(left->left, right->right) && isValid(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isValid(root->left, root->right);
    }
};