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
    
    void rightSide(TreeNode* root, int h, vector<int>& ans) {
        if(!root) return;
        if(ans.size() < h) ans.push_back(root->val);
        rightSide(root->right, h+1, ans);
        rightSide(root->left, h+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        rightSide(root, 1, ans);
        return ans;
        
//         queue<TreeNode*> q;
//         q.push(root);
//         TreeNode* temp=NULL;
        
//         while(!q.empty()) {
//             for(int i=q.size();i;i--) {
//                 temp = q.front();q.pop();
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right) q.push(temp->right);
//             }
//             ans.push_back(temp->val);
//         }
//         return ans;
    }
};