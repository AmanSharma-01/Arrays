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
public:
    unordered_map<TreeNode*, vector<TreeNode*>> mp;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(root->left) {
            mp[root->left].push_back(root);
            mp[root].push_back(root->left);
        }
        if(root->right) {
            mp[root->right].push_back(root);
            mp[root].push_back(root->right);
        }
        inorder(root->right);
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        inorder(root);
        set<TreeNode*> st;
        queue<TreeNode*> q;
        q.push(target);
        st.insert(target);
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                TreeNode* temp = q.front();q.pop();
                if(k==0) ans.push_back(temp->val);
                for(auto nxt: mp[temp]) {
                    if(st.find(nxt) == st.end()) {
                        q.push(nxt);
                        st.insert(nxt);
                    }
                }
            }
            if(k==0) return ans;
            k--;
        }
        return {};
    }
};
















