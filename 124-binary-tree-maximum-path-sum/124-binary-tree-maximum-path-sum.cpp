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
    int ans=INT_MIN;
    
    int path(TreeNode* root) {
        if(!root) return 0;
        int left = path(root->left);
        int right = path(root->right);
        
        int selfCand = root->val + max(0, left) + max(0, right);
        ans = max(ans, selfCand);
        
        return root->val + (max(0, max(left, right)));
    }
    
    int maxPathSum(TreeNode* root) {
        path(root);
        return ans;
    }
};