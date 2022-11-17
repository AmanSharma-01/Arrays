class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=1;j++) {
                int pro =0;
                if(j) {
                    pro = max(dp[i+1][0]-nums[i], dp[i+1][1]);
                } else {
                    pro = max(dp[i+1][1]+nums[i]-fee, dp[i+1][0]);
                }
                dp[i][j] = pro;
            }
        }
        return dp[0][1];
    }
};