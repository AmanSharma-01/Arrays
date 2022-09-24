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
    
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        int l=0,h=ans.size()-1;
        
        while(l<h) {
            if(ans[l]+ans[h]==k) return true;
            else if(ans[l]+ans[h]<k) l++;
            else h--;
        }
        return false;
    }
};