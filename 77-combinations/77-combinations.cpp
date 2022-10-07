class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    
    void recur(int n, int k, int idx) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx;i<=n;i++) {
            curr.push_back(i);
            recur(n, k, i+1);
            curr.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        recur(n, k, 1);
        return ans;
    }
};