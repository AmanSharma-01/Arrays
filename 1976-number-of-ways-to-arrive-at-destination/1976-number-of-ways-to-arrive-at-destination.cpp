class Solution {
public:
    using pi = pair<long long, int>;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        int mod = 1e9+7;
        vector<long long> dis(n, 1e18), ways(n, 0);
        dis[0]=0;
        ways[0]=1;
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push({0, 0}); // {dist, node};
        
        while(!q.empty()) {
            long long currDist = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(auto it: adj[node]) {
                auto nxt = it.first;
                auto edW = it.second;
                
                if(edW + currDist < dis[nxt]) {
                    dis[nxt] = edW+currDist;
                    ways[nxt] = ways[node];
                    q.push({edW+currDist, nxt});
                }
                else if(edW+currDist == dis[nxt]) {
                    ways[nxt] = (ways[nxt] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};