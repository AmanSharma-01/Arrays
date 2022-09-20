class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount=0;
        int low=0, high=0;
        int ans=0;
        
        while(high < nums.size()) {
            if(nums[high] == 0) zeroCount++;
            
            while(zeroCount > k) {
                if(nums[low] == 0) zeroCount--;
                low++;
            }
            ans = max(ans, high-low+1);
            high++;
        }
        return ans;
    }
};