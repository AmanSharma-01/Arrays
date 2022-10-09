class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> mp;
        vector<int> count(num, 0);
        queue<int> q;
        int res=0;
        int n = pre.size();
        
        for(int i=0;i<n;i++) {
            mp[pre[i][1]].push_back(pre[i][0]);
            count[pre[i][0]]++;
        }
        
        for(int i=0;i<num;i++) {
            if(count[i]==0) q.push(i);
        }
        
        while(!q.empty()) {
            res++;
            int top = q.front();q.pop();
            for(auto nxt: mp[top]) {
                count[nxt]--;
                if(count[nxt]==0) q.push(nxt);
            }
        }
        
        return res==num;
    }
};