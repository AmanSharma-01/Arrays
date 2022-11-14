class Solution {
private:
    int findMaxCherry(vector<vector<int>>& grid, int i, int c1, int c2, int row, int col, vector<vector<vector<int>>>& dp) {
        if(c1<0 || c1>=col || c2<0 || c2>=col) {
            return -1e8;
        }
        if(i == row-1) {
            if(c1 == c2) return grid[i][c1];
            else return grid[i][c1]+grid[i][c2];
        }
        if(dp[i][c1][c2] != -1) return dp[i][c1][c2];
        int maxi = -1e8;
        for(int d1=-1;d1<=1;d1++) {
            for(int d2=-1;d2<=1;d2++) {
                int value=0;
                if(c1 == c2) value = grid[i][c1];
                else value = grid[i][c1]+grid[i][c2];
                value += findMaxCherry(grid, i+1, c1 + d1, c2 + d2, row, col, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][c1][c2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ans=0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        ans = findMaxCherry(grid, 0, 0, c-1, r, c, dp); // {i, j1, j2, r, c}
        return ans;
    }
};