class Solution {
public:
    
    int maxArea(vector<int>& heights) {
        for(auto i: heights) cout<< i<<" ";
        int ans = 0;
        int n = heights.size();
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];st.pop();
                int w = st.empty() ? i : i-st.top()-1;
                ans = max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(m, vector<int> (n+1, 0));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0) {
                    dp[0][j] = mat[0][j]-'0';
                } else if(mat[i][j] == '1') {
                    dp[i][j] = dp[i-1][j]+1;
                } else if(mat[i][j] == '0') {
                    dp[i][j] = 0;
                }
            }
            ans = max(ans, maxArea(dp[i]));
        }
        return ans;
    }
};