class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
    
    void dfs(vector<vector<int>>& graph, int idx) {
        if(idx == n-1) {
            curr.push_back(idx);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        
        for(auto i: graph[idx]) {
            curr.push_back(idx);
            dfs(graph, i);
            curr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dfs(graph, 0);
        return ans;
    }
};