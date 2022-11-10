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
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int st, int ed, int& ptr) {
        if(st>ed) return NULL;
        int idx=st;
        while(idx<=ed && inorder[idx] != preorder[ptr]) idx++;
        TreeNode* root = new TreeNode(preorder[ptr++]);
        root->left = bt(preorder, inorder, st, idx-1, ptr);
        root->right = bt(preorder, inorder, idx+1, ed, ptr);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int ptr=0;
        return bt(preorder, inorder, 0, n-1, ptr);
    }
};