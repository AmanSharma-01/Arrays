class Solution {
public:
    int m,n;
    int dp[201][201]{};
    int dfs(vector<vector<int>>& mat, int r, int c, int prev) {
        if(r<0||r>=m||c<0||c>=n||mat[r][c]<=prev) return 0;
        if(dp[r][c]) return dp[r][c];
        return dp[r][c] =  1 + max({dfs(mat, r+1, c, mat[r][c]),
                       dfs(mat, r-1, c, mat[r][c]),
                       dfs(mat, r, c+1, mat[r][c]),
                       dfs(mat, r, c-1, mat[r][c])});
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int maxLen = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                maxLen = max(maxLen, dfs(mat, i, j, INT_MIN));
            }
        }
        
        return maxLen;
    }
};