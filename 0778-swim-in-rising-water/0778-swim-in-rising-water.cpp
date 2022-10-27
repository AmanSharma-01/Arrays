class Solution {
public:
    using pi = pair<int, pair<int, int>>;
    vector<vector<int>> dir = {{1,-1,0,0}, {0,0,1,-1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pi, vector<pi>, greater<pi>> q;
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        
        while(!q.empty()) {
            pi top = q.top();q.pop();
            int r = top.second.first;
            int c = top.second.second;
            
            if(r == n-1 && c == n-1) {
                return top.first;
            }
            
            for(int i=0;i<4;i++) {
                int nr = r + dir[0][i];
                int nc = c + dir[1][i];
                
                if(nr<0||nc<0||nr>=n||nc>=n||vis[nr][nc]==true) continue;
                vis[nr][nc] = true;
                q.push({max(top.first, grid[nr][nc]), {nr, nc}});
            }
        }
        return 0;
    }
};