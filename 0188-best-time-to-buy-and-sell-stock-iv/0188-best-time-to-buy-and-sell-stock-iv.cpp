class Solution {
private:
    int findProfit(int idx, int buy, int cap, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if(idx == nums.size() || cap==0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        if(buy) {
            return dp[idx][buy][cap] = max(findProfit(idx+1, 0, cap, nums, dp)-nums[idx], findProfit(idx+1, 1, cap, nums, dp));
        } else {
            return dp[idx][buy][cap] = max(findProfit(idx+1, 1, cap-1, nums, dp)+nums[idx], findProfit(idx+1, 0, cap, nums, dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return findProfit(0, 1, k, nums, dp);
    }
};