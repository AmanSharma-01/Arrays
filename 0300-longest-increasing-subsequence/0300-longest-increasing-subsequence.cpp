class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for(auto num: nums) {
            int low=0, high=res.size(), mid;
            while(low<high) {
                mid = low + (high-low)/2;
                if(res[mid] < num) low = mid+1;
                else high=mid;
            }
            if(high == res.size()) res.push_back(num);
            else res[high] = num;
        }
        
        return res.size();
        
//         vector<int> dp(n, 1);
//         int ans=0;
//         for(int i=0;i<n;i++) {
//             for(int j=i;j>=0;j--) {
//                 if(nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }
        
//         return ans;
    }
};