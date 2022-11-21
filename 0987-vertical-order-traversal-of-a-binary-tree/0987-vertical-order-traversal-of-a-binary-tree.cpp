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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // {root, {vertical, height}}
        while(!q.empty()) {
            auto p = q.front();q.pop();
            TreeNode* node = p.first;
            int ver = p.second.first;
            int h = p.second.second;
            nodes[ver][h].insert(node->val);
            if(node->left) q.push({node->left, {ver-1, h+1}});
            if(node->right) q.push({node->right, {ver+1, h+1}});
        }
        
        vector<vector<int>> ans;
        
        for(auto p: nodes) {
            vector<int> col;
            for(auto x: p.second) {
                col.insert(col.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};









