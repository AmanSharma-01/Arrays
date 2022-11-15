class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<vector<int>> buckets(n+1);
        vector<int> ans;
        for(auto num: nums) mp[num]++;
        
        for(auto it: mp) {
            buckets[it.second].push_back(it.first);
        }
        reverse(buckets.begin(), buckets.end());
        
        while(k>0) {
            for(auto bucket: buckets) {
                for(auto it: bucket) {
                    ans.push_back(it);
                    if(ans.size() == k) return ans;
                }
            }
        }
        
        return ans;
    }
};