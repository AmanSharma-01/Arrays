class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int m = grid.size();
        int n = grid[0].size();
        
        int r=0,c=n-1;
        
        while(r<m) {
            while(c>=0 && grid[r][c]<0) c--;
            ans+=n-c-1;
            r++;
        }
        return ans;
//         for(int i=m-1;i>=0;i--) {
//             for(int j=n-1;j>=0;j--) {
//                 if(grid[i][j] < 0) ans++;
//                 else break;
//             }
//         }
        
//         return ans;
    }
};