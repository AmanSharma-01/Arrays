class Solution {
public:
    vector<vector<int>> dir = {{1,-1,0,0}, {0,0,1,-1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        int dis=0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==0) q.push({i, j});
                else if(mat[i][j] == 1) mat[i][j]=-1;
            }
        }
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                auto top = q.front();q.pop();
                
                for(int j=0;j<4;j++) {
                    int nr = top.first + dir[0][j];
                    int nc = top.second + dir[1][j];
                    
                    if(nr<0||nr>=m||nc<0||nc>=n||mat[nr][nc] != -1) continue;
                    mat[nr][nc] = dis+1;
                    q.push({nr, nc});
                }
            }
            dis++;
        }
        return mat;
    }
};