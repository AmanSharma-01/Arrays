class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(2e4, 0);
        for(int i=0;i<nums.size();i++) {
            dp[nums[i]] += nums[i];
        }
        int take=0,takei=0,skip=0,skipi=0;
        
        for(auto num: dp) {
            takei = num+skip;
            skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        
        return max(take, skip);
    }
};