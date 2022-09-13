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
    int ans=0;
    vector<int> temp;
    
    void count(TreeNode* root, int tar) {
        if(!root) return;
        temp.push_back(root->val);
        count(root->left, tar);
        count(root->right, tar);
        long long sum=0;
        for(int i=temp.size()-1;i>=0;i--) {
            sum+=temp[i];
            if(sum == tar) ans++;
        }
        temp.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        count(root, targetSum);
        return ans;
    }
};