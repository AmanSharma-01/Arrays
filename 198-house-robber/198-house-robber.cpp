class Solution {
public:
    int rob(vector<int>& nums) {
        int takei=0,take=0,skipi=0,skip=0;
        for(int i=0;i<nums.size();i++) {
            takei = nums[i] + skip;
            skipi = max(take, skip);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};