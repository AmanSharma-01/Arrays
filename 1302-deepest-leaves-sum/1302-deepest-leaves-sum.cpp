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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        
        while(!q.empty()) {
            int temp=0;
            for(int i=q.size();i;i--) {
                TreeNode *top = q.front();q.pop();
                temp += top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            ans = temp;
        }
        
        return ans;
    }
};