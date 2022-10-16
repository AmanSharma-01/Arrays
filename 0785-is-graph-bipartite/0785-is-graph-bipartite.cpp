class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int i, int c, vector<int>& vis, vector<int>& col) {
        vis[i] = 1;
        col[i] = c;
        
        for(auto nxt: graph[i]) {
            if(vis[nxt] == 0) {
                if(dfs(graph, nxt, 1^c, vis, col)==false) {
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
        vector<int> vis(n, 0);
        vector<int> col(n, 0);
        
        for(int i=0;i<n;i++) {
            if(vis[i]==0 && dfs(graph, i, 0, vis, col) == false) {
                return false;
            }
        }
        return true;
    }
};