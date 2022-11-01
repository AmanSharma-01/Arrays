class Solution {
private:
    vector<vector<int>> dir = {{1, -1, 0, 0}, {0, 0, 1, -1}};
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();
        if(r<0||r>=n||c<0||c>=m||grid[r][c]=='0') return;
        grid[r][c] = '0';
        for(int i=0;i<4;i++) {
            int nr = r + dir[0][i];
            int nc = c + dir[1][i];
            dfs(grid, nr, nc);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int r=0;r<n;r++) {
            for(int c=0;c<m;c++) {
                if(grid[r][c] == '1') {
                    ans++;
                    dfs(grid, r, c);
                }
            }
        }
        
        return ans;
    }
};