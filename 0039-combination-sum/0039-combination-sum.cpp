class Solution {
private: 
    void recur(vector<int>& can, int tar, int idx, vector<vector<int>> &ans, vector<int> curr) {
        int n = can.size();
        if(tar == 0) {
            ans.push_back(curr);
            return;
        }
        if(idx >= n) {
            return;
        }
        if(can[idx] > tar) {
            return;
        }
        
        for(int i=idx;i<n;i++) {
            curr.push_back(can[i]);
            recur(can, tar-can[i], i, ans, curr);
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        recur(candidates, target, 0, ans, curr);
        return ans;
    }
};