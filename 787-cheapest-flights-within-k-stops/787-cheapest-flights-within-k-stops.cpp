class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> mp;
        queue<pair<int, int>> q;
        vector<int> d(n ,1e9);
        
        for(auto flight: flights)
            mp[flight[0]].push_back({flight[1], flight[2]});
        
        q.push({src, 0});
        d[src]=0;
        int count=0; // number of stops till now.
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                auto [node, val] = q.front();q.pop();
                
                for(auto nxt: mp[node]) {
                    if(val+nxt.second < d[nxt.first]) {
                        d[nxt.first] = val+nxt.second;
                        q.push({nxt.first, d[nxt.first]});
                    }
                }
            }
            count++;
            if(count>k) return d[dst]==1e9 ? -1 : d[dst];
        }
        return d[dst]==1e9 ? -1 : d[dst];
    }
};