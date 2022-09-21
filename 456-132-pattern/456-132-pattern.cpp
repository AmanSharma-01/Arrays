class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int first = INT_MIN; // this is the 2 in 132 pattern
        
        for(int i=n-1;i>=0;i--) {
            if(nums[i] < first) return true; // if we find an element less then first then 132 pattern is present.
            while(!st.empty() && st.top() < nums[i]) { // nums[i] is the 3 in the 132 pattern
                first = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};