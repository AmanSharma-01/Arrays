class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<int> count(n, 0);
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<nums.size();i++) {
            mp[nums[i][0]].push_back(nums[i][1]);
            count[nums[i][1]]++; // indegree
        }
        
        for(int i=0;i<n;i++) {
            if(count[i]==0) q.push(i);
        }
        
        while(!q.empty()) {
            int top = q.front();q.pop();
            ans.push_back(top);
            
            for(auto nxt: mp[top]) {
                count[nxt]--;
                if(count[nxt] == 0) q.push(nxt);
            }
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == n) return ans;
        return {};
    }
};