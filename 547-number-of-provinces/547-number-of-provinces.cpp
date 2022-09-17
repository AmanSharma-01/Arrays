class Solution {
public:
    void dfs(int city, vector<bool>& vis, vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i=0;i<n;i++) {
            if(vis[i] != true && isConnected[city][i]==1) {
                vis[i]=true;
                dfs(i, vis, isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans=0;
        for(int i=0;i<n;i++) {
            if(vis[i] == true) continue;
            vis[i]=true;
            ans++;
            dfs(i, vis, isConnected);
        }
        return ans;
    }
};