class Solution {
public:
    
    bool dfs(vector<int>& arr, int idx, vector<bool>& vis) {
        if(idx < 0 || idx >= arr.size()) return false;
        if(vis[idx] == true) return false;
        if(arr[idx] == 0) return true;
        vis[idx]=true;
        bool t1 = dfs(arr, idx+arr[idx], vis);
        bool t2 = dfs(arr, idx-arr[idx], vis);
        return t1||t2;
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(start >= n) return false;
        vector<bool> vis(n, false);
        return dfs(arr, start, vis);
    }
};