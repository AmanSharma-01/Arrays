class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans=0;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(mat[i-1][j-1] == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                }
                ans+=dp[i][j];
            }
        }
        
        return ans;
    }
};