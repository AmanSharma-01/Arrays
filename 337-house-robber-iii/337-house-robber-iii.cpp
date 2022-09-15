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
    
    void findMaxLoot(TreeNode* root, int& take, int&notTake) {
        if(!root) return;
        int takeLeft=0, notTakeLeft=0, takeRight=0, notTakeRight=0;
        findMaxLoot(root->left, takeLeft, notTakeLeft);
        findMaxLoot(root->right, takeRight, notTakeRight);
        take = root->val + notTakeRight + notTakeLeft;
        notTake = max(takeLeft, notTakeLeft) + max(takeRight, notTakeRight);
    }
    
    int rob(TreeNode* root) {
        int take=0, notTake=0;
        findMaxLoot(root, take, notTake);
        return max(take, notTake);
    }
};