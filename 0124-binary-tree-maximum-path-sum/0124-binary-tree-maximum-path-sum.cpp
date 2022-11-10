class Solution {
private:
    int findMaxPathSum(TreeNode* root, int& ans) {
        if(!root) return 0;
        int left = findMaxPathSum(root->left, ans);
        int right = findMaxPathSum(root->right, ans);
        int self = root->val + max(0, left) + max(0, right);
        ans = max(ans, self);
        return root->val + max(max(0, left), max(0, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        findMaxPathSum(root, ans);
        return ans;
    }
};