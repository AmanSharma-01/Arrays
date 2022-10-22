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
    
    int sumRootToLeaf(TreeNode* root, string curr = "") {
        if(!root) return 0;
        if(!root->left && !root->right) {
            curr+=to_string(root->val);
            cout<<curr<<" ";
            sum += stoi(curr, 0, 2);
            return sum;
        }
        sumRootToLeaf(root->left, curr+to_string(root->val));
        sumRootToLeaf(root->right, curr+to_string(root->val));
        return sum;
    }
};