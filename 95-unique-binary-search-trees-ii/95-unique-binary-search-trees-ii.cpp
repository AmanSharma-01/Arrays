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
    
    vector<TreeNode*> generate(int st, int ed) {
        vector<TreeNode*> ans;
        if(st>ed) {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i=st;i<=ed;i++) {
            auto left = generate(st, i-1);
            auto right = generate(i+1, ed);
            
            for(auto l: left) {
                for(auto r: right) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};