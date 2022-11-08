/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        
        TreeNode *node1 = lca(root->left, p, q);
        TreeNode *node2 = lca(root->right, p, q);
        
        if(node1 && node2) return root;
        if(node1) return node1;
        return node2;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};