class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int low=0, high=0;
        int ans=0;
        int n = nums.size();
        
        while(high < n) {
            mp[nums[high]]++;
            while(mp.size()>k && low<high) {
                mp[nums[low]]--;
                if(mp[nums[low]] == 0) mp.erase(nums[low]);
                low++;
            }
            ans+=high-low+1;
            high++;
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k==1) return atMost(nums, k);
        return atMost(nums, k)-atMost(nums, k-1);
    }
};