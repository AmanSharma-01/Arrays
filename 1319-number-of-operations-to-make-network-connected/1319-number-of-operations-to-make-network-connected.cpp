class Solution {
public:
    
    void dfs(unordered_map<int, vector<int>>& mp, int curr, vector<bool>& vis) {
        vis[curr] = true;
        for(auto nxt: mp[curr]) {
            if(vis[nxt] == false) {
                dfs(mp, nxt, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int con = connections.size();
        if(con < n-1) return -1;
        
        unordered_map<int, vector<int>> mp;
        
        for(auto conn: connections) {
            mp[conn[0]].push_back(conn[1]);
            mp[conn[1]].push_back(conn[0]);
        }
        
        vector<bool> vis(n, false);
        int component=0;

        for(int i=0;i<n;i++) {
            if(vis[i] == false) {
                dfs(mp, i, vis);
                component++;
            }
        }
        return component-1;
    }
};