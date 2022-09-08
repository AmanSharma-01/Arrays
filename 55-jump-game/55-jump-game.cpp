class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR=0;
        for(int i=0;i<nums.size();i++) {
            if(maxR<i) return false;
            maxR = max(maxR, nums[i]+i);
        }
        return true;
    }
};