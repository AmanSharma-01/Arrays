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
    TreeNode* makeBST(vector<int>& nums, int st, int ed) {
        if(st>ed) return NULL;
        int mid = st + (ed-st)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = makeBST(nums, st, mid-1);
        curr->right = makeBST(nums, mid+1, ed);
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return makeBST(nums, 0, n-1);
    }
};