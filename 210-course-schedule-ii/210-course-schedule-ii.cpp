class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        unordered_map<int, vector<int>> mp;
        vector<int> count(num+1, 0);
        queue<int> q;
        vector<int> res;
        
        for(int i=0;i<n;i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            count[prerequisites[i][0]]++;
        }
        
        for(int i=0;i<num;i++) {
            if(count[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int top = q.front();q.pop();
            res.push_back(top);
            for(auto nc: mp[top]) {
                count[nc]--;
                if(count[nc]==0) q.push(nc);
            }
        }
        
        if(res.size()!=num) return {};
        return res;
    }
};