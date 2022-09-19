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
    int widthOfBinaryTree(TreeNode* root) {
        long ans = 0;
        deque<pair<TreeNode*, long>> q;
        q.push_back({root, 0});
        
        while(!q.empty()) {
            long first = q.front().second;
            long last = q.back().second;
            ans = max(ans, last-first+1);
            for(int i=q.size();i;i--) {
                auto [curr, pos] = q.front();q.pop_front();
                long newPos = pos-first;
                if(curr->left) q.push_back({curr->left, 2*newPos});
                if(curr->right) q.push_back({curr->right, 2*newPos+1});
            }
        }
        return ans;
    }
};