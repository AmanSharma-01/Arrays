class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        
        while(!q.empty()) {
            auto top = q.front();q.pop();
            int x = top[0];
            int y = top[1];
            
            if(x<0||x>=m||y<0||y>=n) continue;
            if(x==m-1&&y==n-1) return top[2];
            
            if(grid[x][y] == 1) {
                if(top[3]>0) {
                    top[3]--;
                } else {
                    continue;
                }
            }
            
            if(vis[x][y]!=-1 && vis[x][y] >= top[3]) {
                continue;
            }
            
            vis[x][y] = top[3];
            
            q.push({x+1, y, top[2]+1, top[3]});
            q.push({x-1, y, top[2]+1, top[3]});
            q.push({x, y+1, top[2]+1, top[3]});
            q.push({x, y-1, top[2]+1, top[3]});
        }
        
        return -1;
    }
};