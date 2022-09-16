class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    
    void findComb(vector<int>& cand, int tar, int beg) {
        if(tar == 0) {
            ans.push_back(curr);
            return;
        }
        if(tar < 0) {
            return;
        }
        
        for(int i=beg;i<cand.size();i++) {
            if(i>beg && cand[i]==cand[i-1]) continue;
            curr.push_back(cand[i]);
            findComb(cand, tar-cand[i], i+1);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        findComb(cand, target, 0);
        return ans;
    }
};