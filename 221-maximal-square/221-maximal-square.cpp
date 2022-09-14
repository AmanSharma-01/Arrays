class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans=0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        // for(int i=0;i<m;i++) dp[i][0] = mat[i][0]-'0';
        // for(int j=0;j<n;j++) dp[0][j] = mat[0][j]-'0';
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = mat[i][j]-'0';
                if(!(i==0 || j == 0 || dp[i][j] == 0)) {
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};