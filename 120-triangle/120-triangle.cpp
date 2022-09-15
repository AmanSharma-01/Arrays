class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        
        for(int i=m-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                tri[i][j] = min(tri[i+1][j], tri[i+1][j+1]) + tri[i][j];
            }
        }
        return tri[0][0];
    }
};