class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i!=0 && j!=0 && mat[i][j] == 1) {
                    mat[i][j] = min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]})+1;
                }
                ans+=mat[i][j];
            }
        }
        
        return ans;
    }
};