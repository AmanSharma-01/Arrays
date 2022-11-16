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
    vector<int> path;
    void findNumberOfPaths(TreeNode* root, int tar, int& ans) {
        if(!root) return;
        path.push_back(root->val);
        findNumberOfPaths(root->left, tar, ans);
        findNumberOfPaths(root->right, tar, ans);
        long long sum=0;
        for(int i=path.size()-1;i>=0;i--) {
            sum += path[i];
            if(sum == tar) ans++;
        }
        path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        findNumberOfPaths(root, targetSum, ans);
        return ans;
    }
};