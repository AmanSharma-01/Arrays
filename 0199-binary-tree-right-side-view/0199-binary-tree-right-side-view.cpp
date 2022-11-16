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
private:
    void findRight(TreeNode* root, int h, vector<int>& ans) {
        if(!root) return;
        if(ans.size() <= h) ans.push_back(root->val);
        findRight(root->right, h+1, ans);
        findRight(root->left, h+1, ans);
    } 
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        findRight(root, 0, ans);
        return ans;
    }
};