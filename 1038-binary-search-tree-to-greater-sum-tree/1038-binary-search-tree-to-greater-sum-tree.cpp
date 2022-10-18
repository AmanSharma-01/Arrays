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
    int sum=0;
    
    TreeNode* greaterTree(TreeNode *node) {
        if(!node) return NULL;
        greaterTree(node->right);
        sum += node->val;
        node->val = sum;
        greaterTree(node->left);
        return node;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        return greaterTree(root);
    }
};