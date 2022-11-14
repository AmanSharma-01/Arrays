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
    int findMinSwapsForLevel(vector<int>& nums) {
        vector<pair<int, int>> arr;
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++) {
            if(arr[i].second == i) continue;
            else {
                ans++;
                swap(arr[i], arr[arr[i].second]);
                i--;
            }
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        int ans=0;
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                TreeNode* top = q.front();q.pop();
                temp.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            ans += findMinSwapsForLevel(temp);
            temp.clear();
        }
        return ans;
    }
};