class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%2) return false;
        int tar = total/2;
        
        vector<vector<bool>> dp(n+1, vector<bool> (tar+1, false));
        for(int i=0;i<tar+1;i++) dp[0][i]=false;
        for(int i=0;i<n+1;i++) dp[i][0]=true;
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<tar+1;j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][tar];
    }
};