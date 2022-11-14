class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<int> st;
        for(int i = 0; i < n/2; ++i) st.insert(nums[i] + nums[n-i-1]);
        return st.size();
    }
};