class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        queue<int> q;
        vector<int> ans;
        int es = edges.size();
        
        for(int i=0;i<es;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(degree[i]==1) q.push(i);
        }
        
        while(n > 2) {
            int size = q.size();
            n -= size;
            
            for(int i=size;i;i--) {
                int top = q.front();q.pop();
                for(auto nxt: adj[top]) {
                    degree[nxt]--;
                    if(degree[nxt] == 1) q.push(nxt);
                }
            }
        }
        
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};










