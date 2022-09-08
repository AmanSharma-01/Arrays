class Solution {
public:
    using pi = pair<int, int>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pi> q;
        vector<int> ans;
        
        for(int i=0;i<k;i++) {
            q.push({nums[i], i});
        }
        ans.push_back(q.top().first);
        
        for(int i=k;i<nums.size();i++) {
            q.push({nums[i], i});
            
            while(!q.empty() && q.top().second <= i-k)q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};