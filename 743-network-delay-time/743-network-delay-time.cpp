class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int s = times.size();
        unordered_map<int, vector<pair<int, int>>> mp;
        vector<int> t(n+1, INT_MAX);
        t[0]=0;
        t[k]=0;
        int ans=0;
        
        for(int i=0;i<s;i++) {
            mp[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        queue<pair<int, int>> q;
        q.push({k, 0});
        
        while(!q.empty()) {
            auto top = q.front();q.pop();
            for(auto nxt: mp[top.first]) {
                if(top.second+nxt.second < t[nxt.first]) {
                    t[nxt.first] = top.second+nxt.second;
                    q.push({nxt.first, top.second+nxt.second});
                }
            }
        }
        
        for(auto ti:t) ans=max(ans, ti);
        
        return ans == INT_MAX ? -1 : ans;
    }
};