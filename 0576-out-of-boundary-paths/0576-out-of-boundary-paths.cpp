class Solution {
public:
    vector<vector<int>> dir = {{1,-1,0,0}, {0,0,1,-1}};
    int dp[55][55][55] = {};
    
    int dfs(int r, int c, int moves, int m, int n) {
        if(r<0||r>=m||c<0||c>=n) return 1;
        if(moves==0) return 0;
        
        if(dp[r][c][moves] != -1) return dp[r][c][moves];
        
        int ans=0;
        for(int i=0;i<4;i++) {
            int nr = r + dir[0][i];
            int nc = c + dir[1][i];
            ans = (ans + dfs(nr, nc, moves-1, m, n)) % 1000000007;
        }
        return dp[r][c][moves] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int r, int c) {
        memset(dp, -1, sizeof(dp));
        return dfs(r, c, maxMove, m, n);;
    }
};