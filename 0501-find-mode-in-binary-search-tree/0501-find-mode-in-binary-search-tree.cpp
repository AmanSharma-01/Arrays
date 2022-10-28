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
    
    void inorder(TreeNode* root, unordered_map<int, int>& mp) {
        if(!root) return;
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;
        inorder(root, mp);
        int maxFreq=0;
        
        for(auto i: mp)
            if(i.second > maxFreq) 
                maxFreq = i.second;
        
        for(auto i: mp)
            if(i.second == maxFreq)
                ans.push_back(i.first);
        
        
        return ans;
    }
};