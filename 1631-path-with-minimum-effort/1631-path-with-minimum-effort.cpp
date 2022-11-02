class Solution {
public:
    using pi = pair<int, pair<int, int>>;
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        
        priority_queue<pi, vector<pi>, greater<pi>> q;
        vector<vector<int>> eff(n, vector<int>(m, 1e9));
        vector<vector<int>> dir = {{1,-1,0,0}, {0,0,1,-1}};
        
        eff[0][0] = 0;
        q.push({0, {0, 0}});
        
        while(!q.empty()) {
            auto it = q.top();q.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1) return effort;
            
            for(int i=0;i<4;i++) {
                int nr = r + dir[0][i];
                int nc = c + dir[1][i];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                int newEffort = max(abs(h[r][c]-h[nr][nc]), effort);
                
                if(newEffort < eff[nr][nc]) {
                    eff[nr][nc] = newEffort;
                    q.push({newEffort, {nr, nc}});
                }
                
            }
        }
        return -1;
    }
};