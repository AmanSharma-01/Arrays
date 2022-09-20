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
    
    TreeNode *bd(vector<int>& inorder, vector<int>& postorder, int& ptr, int st, int ed) {
        if(st > ed) return NULL;
        int idx = ed;
        
        while(idx>=0 && inorder[idx] != postorder[ptr]) idx--;
        TreeNode* curr = new TreeNode(postorder[ptr--]);
        curr->right = bd(inorder, postorder, ptr, idx+1, ed);
        curr->left = bd(inorder, postorder, ptr, st, idx-1);
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ptr=inorder.size()-1;
        return bd(inorder, postorder, ptr, 0, inorder.size()-1);
    }
};