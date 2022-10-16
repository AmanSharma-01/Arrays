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
    TreeNode* makeTree(vector<int>& preorder, int st, int ed) {
        if(st>ed) return NULL;
        TreeNode* root = new TreeNode(preorder[st]);
        int i = st+1;
        for(;i<=ed;i++) {
            if(preorder[st] < preorder[i]) break;
        }
        root->left = makeTree(preorder, st+1, i-1);
        root->right = makeTree(preorder, i, ed);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return makeTree(preorder, 0, preorder.size()-1);
    }
};