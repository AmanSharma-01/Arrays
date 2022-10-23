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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            bool flag=false;
            for(int i=q.size();i;i--) {
                TreeNode* top = q.front();q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                if(top->left && top->right)
                {
                    if((top->left->val == x || top->left->val == y)&&(top->right->val == x || top->right->val == y)) return false;
                }
                
                if(top->left&& (top->left->val == x || top->left->val == y))
                {
                    if(flag)return true;
                    else flag=true;
                }
                 if(top->right && (top->right->val == x || top->right->val == y))
                {
                    if(flag)return true;
                    else flag=true;
                }
            }
            if(flag)return false;
        }
        return false;
        
    }
};