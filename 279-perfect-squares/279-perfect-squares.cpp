class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0]=0, dp[1]=1;
        
        for(int i=0;i<=n;i++) {
            for(int j=0; i-j*j>=0; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};