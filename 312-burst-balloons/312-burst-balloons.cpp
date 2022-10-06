class Solution {
public:
    
    int recur(int st, int ed, vector<int>& nums, vector<vector<int>>& dp) {
        if(st>ed) return 0;
        if(dp[st][ed]!=-1) return dp[st][ed];
        
        int maxi = INT_MIN;
        
        for(int k=st;k<=ed;k++) {
            int cost = nums[k]*nums[st-1]*nums[ed+1] + recur(st, k-1, nums, dp) + recur(k+1, ed, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[st][ed]=maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recur(1, n, nums, dp);
    }
};