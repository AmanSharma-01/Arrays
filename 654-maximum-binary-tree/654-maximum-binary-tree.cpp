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
    
    int max(vector<int>& nums, int st, int ed) {
        int index = st;
        int m=INT_MIN;
        for(int i=st;i<ed;i++) {
            if(nums[i]>nums[index]) {
                index = i;
            }
        }
        return index;
    }
    
    TreeNode* dfs(vector<int>& nums, int st, int ed) {
        if(st==ed) return NULL;
        int mi = max(nums, st, ed);
        TreeNode *root = new TreeNode(nums[mi]);
        root->left = dfs(nums, st, mi);
        root->right = dfs(nums, mi+1, ed);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n);
    }
};