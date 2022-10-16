class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    
    void dfs(int n, int k, int idx) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        if(idx > n) {
            return;
        }
        
        for(int i=idx;i<=n;i++) {
            curr.push_back(i);
            dfs(n, k, i+1);
            curr.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};