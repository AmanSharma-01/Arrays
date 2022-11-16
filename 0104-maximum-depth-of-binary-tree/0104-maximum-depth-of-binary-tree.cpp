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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                TreeNode *top = q.front();q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            depth++;
        }
        
        return depth;
        // if(!root) return 0;
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};