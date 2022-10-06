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
    TreeNode* first, *prev, *middle, *last;
public:
//     vector<int> ans;
//     int idx;
//     void inorder(TreeNode* root) {
//         if(!root) return;
//         inorder(root->left);
//         ans.push_back(root->val);
//         inorder(root->right);
//     }
    
//     void inorder2(TreeNode* root) {
//         if(!root) return;
//         inorder2(root->left);
//         root->val = ans[idx++];
//         inorder2(root->right);
//     }
    
    
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        
        if(prev != NULL && root->val < prev->val) {
            if(first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
        
        // inorder(root);
        // idx=0;
        // sort(ans.begin(), ans.end());
        // inorder2(root);
    }
};