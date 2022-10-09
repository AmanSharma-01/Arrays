class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    
    void dfs(int k, int tar, int idx) {
        if(curr.size()==k && tar == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(curr.size() < k) {
            for(int i=curr.empty() ? 1 : idx+1;i<=9;i++) {
                curr.push_back(i);
                dfs(k, tar-i, i);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        unordered_set<int> st;
        dfs(k, n, 1);
        return ans;
    }
};