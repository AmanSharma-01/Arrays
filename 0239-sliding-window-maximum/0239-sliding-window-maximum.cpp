class Solution {
public:
    using pi = pair<int, int>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pi> q;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<k;i++) {
            q.push({nums[i], i});
        }
        ans.push_back(q.top().first);
        for(int i=k;i<n;i++) {
            q.push({nums[i], i});
            while(q.top().second <= i-k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};