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
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> dp(n, 1);
        for(int i=1;i<m;i++) {
            vector<int> curr(n, 0);
            for(int j=0;j<n;j++) {
                if(j==0) curr[j]=1;
                else {
                    curr[j] = curr[j-1]+dp[j];
                }
            }
            dp=curr;
        }
        return dp[n-1];
        // return recur(m-1, n-1, dp);
    }
};