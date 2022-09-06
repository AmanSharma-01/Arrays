class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(auto num: nums) {
            int s=0, e=res.size(), mid;
            while(s<e) {
                mid = s+(e-s)/2;
                if(res[mid] < num) s = mid+1;
                else e = mid;
            }
            if(e == res.size()) res.push_back(num);
            else res[e] = num;
        }
        
        return res.size();
        
//         vector<int> dp(n, 1);
//         int ans=0;
        
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<i;j++) {
//                 if(nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }
//         return ans;
    }
};