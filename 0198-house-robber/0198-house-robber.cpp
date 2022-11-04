class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int take=0,takei=0,skip=0,skipi=0;
        
        for(int i=0;i<n;i++) {
            takei = nums[i]+skip;
            skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        
        return max(take, skip);
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int> (2, 0));
//         dp[0][0]=0;
//         dp[0][1]=nums[0];
//         dp[1][0]=max(dp[0][1], dp[0][0]);
//         dp[1][1]=nums[1];
        
//         for(int i=2;i<n;i++) {
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
//             dp[i][1] = nums[i] + dp[i-1][0];
//         }
        
//         return max(dp[n-1][0], dp[n-1][1]);
    }
};