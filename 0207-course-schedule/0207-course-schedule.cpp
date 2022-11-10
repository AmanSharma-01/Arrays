class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<int> count(n, 0);
        queue<int> q;
        int res=0;
        
        for(int i=0;i<nums.size();i++) {
            mp[nums[i][0]].push_back(nums[i][1]);
            count[nums[i][1]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(count[i]==0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            res++;
            int top=q.front();q.pop();
            for(auto nxt: mp[top]) {
                count[nxt]--;
                if(count[nxt]==0) q.push(nxt);
            }
        }
        
        return res==n;
    }
};