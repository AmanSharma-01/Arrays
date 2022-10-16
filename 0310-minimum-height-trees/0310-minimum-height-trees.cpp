class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) 
            return {};
        if(n==1) 
            return {0};
        vector<int> ans;
        vector<vector<int>> adj(n+1);
        queue<int> q;
        vector<int> degree(n, 0);
        
        for(auto ed: edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
            degree[ed[0]]++;
            degree[ed[1]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(degree[i] == 1) q.push(i);
        }
        
        while(n>2) {
            int size = q.size();
            n-=size;
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