class Solution {
public:
    int8_t dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};
    
    bool isPossible(vector<int>& nums, int tar, int i=0) {
        if(tar == 0) return true;
        if(i>=nums.size() || tar < 0) return false;
        if(dp[i][tar] != -1) return dp[i][tar];
        return dp[i][tar] = isPossible(nums, tar-nums[i], i+1) || isPossible(nums, tar, i+1);
    }
    
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%2) return false;
        int tar = total/2;
        return isPossible(nums, tar);
    }
};