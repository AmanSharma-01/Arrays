class Solution {
private:
    // int recur(int r, int c, vector<vector<int>>& dp) {
    //     if(r<0||c<0) return 0;
    //     if(dp[r][c] != -1) return dp[r][c];
    //     if(r==0||c==0) return 1;
    //     return dp[r][c] = recur(r-1, c, dp)+recur(r, c-1, dp);
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 || j==0) dp[i][j]=1;
                else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
        // return recur(m-1, n-1, dp);
    }
};