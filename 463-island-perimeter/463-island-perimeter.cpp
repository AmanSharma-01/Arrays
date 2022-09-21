class Solution {
public:
    int m,n;
    
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis, int r, int c) {
        if(r<0||r>=m||c<0||c>=n||grid[r][c]==0) return 1;
        if(vis[r][c]) return 0;
        vis[r][c]=true;
        int ans = 0;
        ans += dfs(grid, vis, r+1, c);
        ans += dfs(grid, vis, r-1, c);
        ans += dfs(grid, vis, r, c+1);
        ans += dfs(grid, vis, r, c-1);
        
        return ans;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j])
                    return dfs(grid, vis, i, j);
            }
        }
        return -1;
    }
};