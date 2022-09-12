class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int top=0, bottom=m-1, left=0, right=n-1;
        int dir=1;
        while(ans.size() != n*m) {
            if(dir == 1) {
                for(int i=left;i<=right;i++) ans.push_back(mat[top][i]);
                dir=2;
                top++;
            }
            else if(dir == 2) {
                for(int i=top;i<=bottom;i++) ans.push_back(mat[i][right]);
                dir=3;
                right--;
            }
            else if(dir == 3) {
                for(int i=right;i>=left;i--) ans.push_back(mat[bottom][i]);
                dir=4;
                bottom--;
            }
            else if(dir == 4) {
                for(int i=bottom;i>=top;i--) ans.push_back(mat[i][left]);
                dir=1;
                left++;
            }
        }
        return ans;
    }
};