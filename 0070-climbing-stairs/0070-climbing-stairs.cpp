class Solution {
private:
    int climb(int n, vector<int>& dp) {
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climb(n-1, dp)+climb(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climb(n, dp);
    }
};