class Solution {
public:
    
    int findLength(string& t1, string& t2, int p1, int p2, vector<vector<int>>& dp) {
        if(p1<0||p2<0) {
            return 0;
        }
        
        if(dp[p1][p2] != -1) {
            return dp[p1][p2];
        }
        
        if(t1[p1]==t2[p2]) {
            return dp[p1][p2] = 1 + findLength(t1, t2, p1-1, p2-1, dp);
        } else {
            return dp[p1][p2] = max(findLength(t1, t2, p1, p2-1, dp), findLength(t1, t2, p1-1, p2, dp));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0;i<n+1;i++) dp[i][0] = 0;
        for(int i=0;i<m+1;i++) dp[0][i] = 0;
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<m+1;j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        // return findLength(text1, text2, n-1, m-1, dp);
    }
};