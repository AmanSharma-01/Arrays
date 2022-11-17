class Solution {
// private:
//     int findProfit(vector<int>& nums, int idx, int buy, int cap, vector<vector<vector<int>>>& dp) {
//         if(idx == nums.size() || cap == 0) { // base case
//             return 0;
//         }
        
//         if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        
//         if(buy) {
//             return dp[idx][buy][cap] = max(findProfit(nums, idx+1, 0, cap, dp)-nums[idx], findProfit(nums, idx+1, 1, cap, dp));
//         } else {
//             return dp[idx][buy][cap] = max(findProfit(nums, idx+1, 1, cap-1, dp)+nums[idx], findProfit(nums, idx+1, 0, cap, dp));
//         }
//     }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        
        for(int i=n-1;i>=0;i--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cap=1;cap<=2;cap++) {
                    long pro = 0;
                    if(buy) {
                         pro = max(after[0][cap]-nums[i], after[1][cap]);
                    } else {
                         pro = max(after[1][cap-1]+nums[i], after[0][cap]);
                    }
                    curr[buy][cap] = pro;
                }
                after=curr;
            }
        }
        
        return curr[1][2];
    }
};