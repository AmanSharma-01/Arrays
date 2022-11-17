class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> after(2, 0), curr(2, 0);
        
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=1;j++) {
                int pro =0;
                if(j) {
                    pro = max(after[0]-nums[i], after[1]);
                } else {
                    pro = max(after[1]+nums[i]-fee, after[0]);
                }
                curr[j] = pro;
            }
            after=curr;
        }
        return curr[1];
    }
};