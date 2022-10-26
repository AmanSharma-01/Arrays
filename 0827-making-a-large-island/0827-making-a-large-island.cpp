class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int id) {
        int n = grid.size();
        if(r<0||r>=n||c<0||c>=n||grid[r][c]!=1) return 0;
        grid[r][c]=id;
        
        return 1 + dfs(grid, r+1, c, id) +
            dfs(grid, r-1, c, id) +
            dfs(grid, r, c+1, id) +
            dfs(grid, r, c-1, id);
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int gridId=2;
        int n = grid.size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int size = 0;
                if(grid[i][j] == 1) {
                    size = dfs(grid, i, j, gridId);
                }
                mp[gridId++] = size;
            }
        }
        int ans=mp[2];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) {
                    set<int> st;
                    
                    st.insert(i>0 ? grid[i-1][j]:0);
                    st.insert(i<n-1 ? grid[i+1][j]:0);
                    st.insert(j>0 ? grid[i][j-1]:0);
                    st.insert(j<n-1 ? grid[i][j+1]:0);
                    
                    int totalArea=1;
                    for(auto i:st) {
                        totalArea += mp[i];
                    }
                    ans = max(ans, totalArea);
                }
            }
        }
        
        return ans;
    }
};










