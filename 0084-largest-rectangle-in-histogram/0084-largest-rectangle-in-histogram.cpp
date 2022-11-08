class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        stack<int> st;
        int ans=0;
        
        for(int i=0;i<n+1;i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                int h = nums[st.top()];st.pop();
                int w = st.empty() ? i : i-st.top()-1;
                ans = max(ans, h*w);
            }
            st.push(i);
        }
        return ans;
    }
};