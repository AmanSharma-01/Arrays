class Solution {
public:
    vector<int> vis, col;
    
    bool dfs(unordered_map<int, vector<int>>& mp, int node, int c) {
        vis[node]=1;
        col[node]=c;
        
        for(auto nxt: mp[node]) {
            if(vis[nxt] == 0) {
                if(dfs(mp, nxt, 1^c)==false) return false;
            } else {
                if(col[nxt] == c) return false;
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        for(auto d: dislikes) {
            mp[d[0]].push_back(d[1]);
            mp[d[1]].push_back(d[0]);
        }
        vis.resize(n+1, 0);
        col.resize(n+1, 0);
        
        for(int i=1;i<=n;i++) {
            if(vis[i]==0 && dfs(mp, i, 0) == false) {
                return false;
            }
        }
        
        return true;
    }
};