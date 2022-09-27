class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto flight: flights) {
            mp[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> price(n, 1e9);
        price[src]=0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        int count =0;
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                auto [node, val] = q.front();q.pop();
                
                for(auto nxt: mp[node]) {
                    if(nxt.second+val < price[nxt.first]) {
                        price[nxt.first] = nxt.second+val;
                        q.push({nxt.first, price[nxt.first]});
                    }
                }
                
            }
            count++;
            if(count>k) return price[dst] == 1e9 ? -1 : price[dst];
        }
        
        return price[dst] == 1e9 ? -1 : price[dst];
    }
};