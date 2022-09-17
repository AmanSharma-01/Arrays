class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        unordered_map<int, int> mp;
        int sum=0;
        mp[0]=1;
        
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(mp[sum-k] > 0) {
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
        
//         int ans=0;
//         for(int i=0;i<nums.size();i++) {
//             int sum=0;
//             for(int j=i;j<nums.size();j++) {
//                 sum += nums[j];
//                 if(sum == k) ans++;
//             }
//         }
//         return ans;
    }
};