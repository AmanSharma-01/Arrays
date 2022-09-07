class Solution {
public:
    
    void recourr(vector<int>& cand, int target, int idx, vector<int> curr, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(idx >= cand.size() || target < 0) {
            return;
        }
        
        for(int i=idx;i<cand.size();i++) {
            curr.push_back(cand[i]);
            recourr(cand, target-cand[i], i, curr, ans);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        recourr(candidates, target, 0, curr, ans);
        return ans;
    }
};