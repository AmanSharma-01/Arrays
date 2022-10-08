class Solution {
public:
    vector<int> vis, col;
    
    bool dfs(vector<vector<int>>& graph, int i, int c) {
        vis[i] = 1;
        col[i] = c;
        
        for(auto nxt: graph[i]) {
            if(vis[nxt] == 0) {
                if(dfs(graph, nxt, c^1) == false) {
                    return false;
                }
            } else {
                if(col[nxt] == c) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n, 0);
        col.resize(n, 0);
        
        for(int i=0;i<n;i++) {
            if(vis[i] == 0 && dfs(graph, i, 0)==false) {
                return false;
            }
        }
        
        return true;
    }
};