class Solution {
public:
    vector<int> vis, col;
    
    bool dfs(unordered_map<int, vector<int>>& mp, int curr, int c) {
        vis[curr] = 1;
        col[curr] = c;
        
        for(auto nxt: mp[curr]) {
            if(vis[nxt] == 0) {
                if(dfs(mp, nxt, 1^c) == false) return false;
            } else {
                if(col[nxt] == c) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vis.resize(n+1, 0);
        col.resize(n+1, 0);
        unordered_map<int, vector<int>> mp;
        
        for(auto dis: dislikes) {
            mp[dis[0]].push_back(dis[1]);
            mp[dis[1]].push_back(dis[0]);
        }
        
        for(int i=0;i<n;i++) {
            if(vis[i]==0 && dfs(mp, i, 0) == false) {
                return false;
            }
        }
        return true;
    }
};