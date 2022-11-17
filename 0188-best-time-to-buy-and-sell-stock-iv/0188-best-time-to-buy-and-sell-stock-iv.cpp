class Solution {
private:
    // int findProfit(int idx, int buy, int cap, vector<int>& nums, vector<vector<vector<int>>>& dp) {
    //     if(idx == nums.size() || cap==0) return 0;
    //     if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    //     if(buy) {
    //         return dp[idx][buy][cap] = max(findProfit(idx+1, 0, cap, nums, dp)-nums[idx], findProfit(idx+1, 1, cap, nums, dp));
    //     } else {
    //         return dp[idx][buy][cap] = max(findProfit(idx+1, 1, cap-1, nums, dp)+nums[idx], findProfit(idx+1, 0, cap, nums, dp));
    //     }
    // }
public:
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> after(2, vector<int> (k+1, 0)), curr(2, vector<int> (k+1, 0));
        
        for(int idx=n-1;idx>=0;idx--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cap=1;cap<=k;cap++) {
                    long pro = 0;
                    if(buy) {
                        pro = max(after[0][cap]-nums[idx], after[1][cap]);
                    } else {
                        pro = max(after[1][cap-1]+nums[idx], after[0][cap]);
                    }
                    curr[buy][cap] = pro;
                }
                after = curr;
            }
        }
        
        return curr[1][k];
    }
};