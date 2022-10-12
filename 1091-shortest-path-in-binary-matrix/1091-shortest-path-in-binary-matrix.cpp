class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans=0;
        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int, int>> q;
        if(grid[0][0] == 0) q.push({0, 0});
        else return -1;
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                auto top = q.front();q.pop();
                if(top.first == n-1 && top.second == n-1) return ans+1;
                for(int i=0;i<8;i++) {
                    int nr = top.first + d[i][0];
                    int nc = top.second + d[i][1];
                    if(nr<0 || nr==n || nc<0 || nc==n || grid[nr][nc]) continue;
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
            ans++;
        }
        
        return -1;
    }
};