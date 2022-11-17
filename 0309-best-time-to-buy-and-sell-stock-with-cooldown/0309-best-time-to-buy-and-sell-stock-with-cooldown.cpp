class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=1;j++) {
                long pro=0;
                if(j) {
                    pro = max(dp[i+1][0]-nums[i], dp[i+1][1]);
                } else {
                    pro = max(dp[i+2][1]+nums[i], dp[i+1][0]);
                }
                dp[i][j]=pro;
            }
        }
        
        return dp[0][1];
    }
};