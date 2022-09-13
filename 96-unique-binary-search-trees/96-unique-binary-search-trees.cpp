class Solution {
public:
    
    int dfs(int n, vector<int>& dp) {
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=0;i<n;i++) {
            int left = dfs(i, dp);
            int right = dfs(n-i-1, dp);
            ans += left*right;
        }
        return dp[n]=ans;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=dp[1]=1;
        return dfs(n, dp);
    }
};