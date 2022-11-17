class Solution {
private:
    int findProfit(vector<int>& nums, int idx, int buy, vector<vector<int>> &dp) {
        if(idx == nums.size()) {
            return 0;
        }
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy) {
            return dp[idx][buy] = max(findProfit(nums, idx+1, 0, dp)-nums[idx], findProfit(nums, idx+1, 1, dp));
        } else {
            return dp[idx][buy] = max(findProfit(nums, idx+1, 1, dp)+nums[idx], findProfit(nums, idx+1, 0, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return findProfit(prices, 0, 1, dp);
    }
};