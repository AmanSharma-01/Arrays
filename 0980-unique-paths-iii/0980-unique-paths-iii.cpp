class Solution {
public:
    int m,n;
    int ans=0;
    int empty=0;
    
    void dfs(vector<vector<int>>& grid, int r, int c, int cnt) {
        if(r<0||r>=m||c<0||c>=n||grid[r][c]==-1) return;
        if(grid[r][c]==2) {
            if(cnt == empty) {
                ans++;
            }
            return;
        }
        
        if(grid[r][c]==0) cnt++;
        
        grid[r][c]=-1;
        dfs(grid, r+1, c, cnt);
        dfs(grid, r-1, c, cnt);
        dfs(grid, r, c+1, cnt);
        dfs(grid, r, c-1, cnt);
        
        grid[r][c]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x_start=INT_MIN, y_start=INT_MIN;
        int zeroCount=0;
        m = grid.size();
        n = grid[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    x_start=i;
                    y_start=j;
                }
                else if(grid[i][j] == 0) {
                    zeroCount++;
                }
            }
        }
        empty=zeroCount;
        dfs(grid, x_start, y_start, 0);
        return ans;
    }
};