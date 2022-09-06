class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0, sum=0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp[sum-k] > 0) {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        
        // for(int i=0;i<n;i++) {
        //     sum=0;
        //     for(int j=i;j<n;j++) {
        //         sum+=nums[j];
        //         if(sum==k) ans++;
        //     }
        // }
        return ans;
    }
};