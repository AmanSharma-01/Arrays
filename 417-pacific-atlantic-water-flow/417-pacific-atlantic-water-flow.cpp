class Solution {
public:
    int m,n;
    vector<vector<int>> dir = {{1,-1,0,0}, {0,0,1,-1}};
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& arr, int r, int c) {
        if(arr[r][c]) return;
        arr[r][c] = true;
        
        for(int i=0;i<4;i++) {
            int nr = r + dir[0][i];
            int nc = c + dir[1][i];
            if(nr<0||nr>=m||nc<0||nc>=n||h[r][c]>h[nr][nc]) continue;
            dfs(h, arr, nr, nc);
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size();
        n = h[0].size();
        
        vector<vector<int>> ans;
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        
        for(int i=0;i<n;i++) {
            dfs(h, pac, 0, i);
            dfs(h, atl, m-1, i);
        }
        
        for(int i=0;i<m;i++) {
            dfs(h, pac, i, 0);
            dfs(h, atl, i, n-1);
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};