class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()]>heights[i]) {
                int h = heights[st.top()];st.pop();
                int w = st.empty() ? i : i-st.top()-1;
                ans = max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
};