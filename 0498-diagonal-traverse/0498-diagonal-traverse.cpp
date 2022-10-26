class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int size = (m-1)+(n-1);
        vector<vector<int>> temp(size+1);
        vector<int> ans;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                temp[i+j].push_back(mat[i][j]);
            }
        }
        int rev=true;
        
        for(int i=0;i<=size;i++) {
            if(rev) reverse(temp[i].begin(), temp[i].end());
            rev = !rev;
        }
        
        for(int i=0;i<=size;i++) {
            for(int j=0;j<temp[i].size();j++) {
                ans.push_back(temp[i][j]);
            }
        }
        
        return ans;
    }
};