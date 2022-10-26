class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c) return mat;
        vector<vector<int>> temp(r, vector<int>(c, 0));
        int ptr1=0,ptr2=0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                temp[ptr1][ptr2++] = mat[i][j];
                if(ptr2>=c) {
                    ptr1++;
                    ptr2=0;
                }
            }
        }
        
        return temp;
    }
};