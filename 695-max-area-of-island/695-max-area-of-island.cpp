class Solution {
public:
    int m,n;
    
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r<0||r>=m||c<0||c>=n||grid[r][c]!=1) return 0;
        int ans = 0;
        grid[r][c]=0;
        ans = dfs(grid, r+1, c) +
            dfs(grid, r-1, c) +
            dfs(grid, r, c+1) +
            dfs(grid, r, c-1);
        return ans+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = INT_MIN;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};