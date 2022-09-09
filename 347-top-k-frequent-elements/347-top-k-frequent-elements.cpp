class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>q;
        vector<int> ans;
        
        for(auto num: nums) mp[num]++;
        
        for(auto i: mp) {
            q.push({i.second, i.first});
        }
        
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};