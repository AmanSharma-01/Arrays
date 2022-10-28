class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int low=0,high=0;
        int maxLen=0;
        while(high < nums.size()) {
            if(nums[high] == 1) high++;
            else {
                maxLen = max(maxLen, high-low);
                low = high+1;
                high++;
            }
        }
        
        return max(maxLen, high-low);
    }
};