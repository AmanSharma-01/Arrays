class Solution {
public:
    vector<vector<int>> dir = {{1,-1,0,0}, {0,0,1,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                pair<int, int> top = q.front();q.pop();
                int r = top.first;
                int c = top.second;
                for(int j=0;j<4;j++) {
                    int nr = r + dir[0][j];
                    int nc = c + dir[1][j];
                    if(nr<0||nr>=m||nc<0||nc>=n||grid[nr][nc]!=1) continue;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
            ans++;
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans == 0 ? 0 : ans-1;
    }
};