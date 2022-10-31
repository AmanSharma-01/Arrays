class Solution {
private:
    bool findSafeNodes(vector<vector<int>>& graph, int curr, vector<int>& path, vector<int>& vis, vector<int>& isSafeNode) {
        vis[curr] = 1;
        path[curr] = 1;
        
        for(auto nxt: graph[curr]) {
            if(vis[nxt] == 0) {
                if(findSafeNodes(graph, nxt, path, vis, isSafeNode) == true) {
                    isSafeNode[curr] = 0;
                    return true;
                }
            } else if(path[nxt] == 1) {
                isSafeNode[curr] = 0;
                return true;
            }
        }
        
        isSafeNode[curr] = 1;
        path[curr] = 0;
        return false;
    }
public:
//     optimizations:- we can use single vectorfor all the states
//     0:- unvisited
//     1:- visited
//     2:- included in current path
//     3:- is Safe state
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> path(n, 0); 
        vector<int> vis(n, 0);
        vector<int> isSafeNode(n, 0);
        
        for(int i=0;i<n;i++) {
            if(vis[i] == 0) {
                findSafeNodes(graph, i, path, vis, isSafeNode);
            }
        }
        
        for(int i=0;i<n;i++) {
            if(isSafeNode[i]==1) ans.push_back(i);
        }
        
        return ans;
    }
};