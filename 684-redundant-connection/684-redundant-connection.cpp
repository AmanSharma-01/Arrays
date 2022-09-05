class Solution {
public:
    
    bool canReach(int e1, int e2, unordered_map<int, vector<int>>& mp, vector<bool>& vis) {
        if(vis[e1]) return true;
        vis[e1] = true;
        for(auto nxt: mp[e1]) {
            if(nxt != e2 && canReach(nxt, e1, mp, vis)) return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> mp;
        vector<bool> vis(n+1, false);
        for(int i=0;i<edges.size();i++) {
           
            for(int j=0;j<n+1;j++)vis[j]=false;
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            if(canReach(edges[i][0], -1, mp, vis)) return edges[i];
        }
        return {};
    }
};