class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<vector<int>> buc(n+1);
        
        for(auto num: nums) {
            mp[num]++;
        }
        
        for(auto i: mp) {
            buc[i.second].push_back(i.first);
        }
        reverse(buc.begin(), buc.end());
        
        for(auto it: buc) {
            for(auto single: it) {
                ans.push_back(single);
                if(ans.size()==k) return ans;
            }
        }
        
        return {};
    }
};