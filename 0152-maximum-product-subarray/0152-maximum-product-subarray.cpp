class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minP=nums[0], maxP=nums[0], ans=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i] < 0) swap(minP, maxP);
            minP = min(minP*nums[i], nums[i]);
            maxP = max(maxP*nums[i], nums[i]);
            ans = max(ans, maxP);
        }
        return ans;
    }
};