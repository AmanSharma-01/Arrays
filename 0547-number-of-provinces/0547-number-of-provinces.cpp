class Solution {
private:
    void dfs(vector<vector<int>>& graph, int city, int nodes, vector<int>& vis) {
        if(vis[city]) return;
        vis[city] = 1;
        
        for(int i=0;i<nodes;i++) {
            if(vis[i] == 0 && graph[city][i]==1) {
                dfs(graph, i, nodes, vis);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        int ans=0;
        
        for(int i=0;i<n;i++) {
            if(vis[i] == 0) {
                dfs(graph, i, n, vis);
                ans++;
            }
        }
        
        return ans;
    }
};