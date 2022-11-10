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
private:
    bool checkMirror(TreeNode *l, TreeNode *r) {
        if(!l&&!r) return true;
        if(!l&&r || l&&!r) return false;
        if(l->val != r->val) return false;
        return checkMirror(l->left, r->right) && checkMirror(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return checkMirror(root->left, root->right);
    }
};