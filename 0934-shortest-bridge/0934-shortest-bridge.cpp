class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    queue<pair<int, int>> q;
    int n=0;
    
    void dfs(vector<vector<int>>& grid, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=n || grid[r][c] == 0 || grid[r][c] == 2) return;
        grid[r][c] = 2;
        q.push({r, c});
        
        for(int i=0;i<4;i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            dfs(grid, nr, nc);
        }
        return;
    }
    
    int bfs(vector<vector<int>>& grid) {
        int ans=0;
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                auto top = q.front();q.pop();
                for(int j=0;j<4;j++) {
                    int nr = top.first + dir[j][0];
                    int nc = top.second + dir[j][1];
                    if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc] == 2) continue;
                    if(grid[nr][nc] == 1) return ans;
                    else if(grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i=0;i<n;i++) {
            bool flag = false;
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return bfs(grid);
    }
};