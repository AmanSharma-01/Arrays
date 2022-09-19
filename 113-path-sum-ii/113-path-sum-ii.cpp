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
    vector<vector<int>> ans;
    vector<int> path;
    
    void getPath(TreeNode* root, int tar) {
        if(!root) return;
        path.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(tar == root->val) {
                ans.push_back(path);
            }
        } else {
            getPath(root->left, tar-root->val);
            getPath(root->right, tar-root->val);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        getPath(root, targetSum);
        return ans;
    }
};