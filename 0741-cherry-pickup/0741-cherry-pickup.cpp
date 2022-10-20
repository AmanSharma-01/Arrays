class Solution {
public:
    int n=0;
    int ans=0;
    
//     void cp1helper(vector<vector<int>>& grid, int i, int j, int clsf) {
//         if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==-1) return;
        
//         if(i == 0 && j == 0) {
//             ans = max(ans, clsf);
//             return;
//         }
        
//         int cherries = grid[i][j];
//         grid[i][j] = 0;
//         cp1helper(grid, i-1, j, clsf+cherries);
//         cp1helper(grid, i, j-1, clsf+cherries);
//         grid[i][j] = cherries;
//     }
    
//     void cp1(vector<vector<int>>& grid, int i, int j, int clsf) {
//         if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==-1) return;
        
//         if(i == n-1 && j == n-1) {
//             cp1helper(grid, n-1, n-1, clsf);
//             return;
//         }
        
//         int cherries = grid[i][j];
//         grid[i][j] = 0;
//         cp1(grid, i+1, j, clsf+cherries);
//         cp1(grid, i, j+1, clsf+cherries);
//         grid[i][j] = cherries;
//     }
    
    int dp[51][51][51] = {};
    
    int cp1(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1+c1-r2;
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        
        if(r1 == n-1 && c1 == n-1) {
            return grid[r1][c1];
        }
        
        if(dp[r1][c1][r2] != 0) {
            return dp[r1][c1][r2];
        }
        
        int ch = 0;
        if(r1==r2 && c1==c2) {
            ch+=grid[r1][c1];
        } else {
            ch += grid[r1][c1] + grid[r2][c2];
        }
        
        int f1 = cp1(grid, r1+1, c1, r2+1);
        int f2 = cp1(grid, r1, c1+1, r2);
        int f3 = cp1(grid, r1+1, c1, r2);
        int f4 = cp1(grid, r1, c1+1, r2+1);
        
        ch += max({f1,f2,f3,f4});
        return dp[r1][c1][r2] = ch;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        if(n==1) return grid[0][0];
        memset(dp, 0, sizeof(dp));
        return max(0, cp1(grid, 0, 0, 0));
    }
};









