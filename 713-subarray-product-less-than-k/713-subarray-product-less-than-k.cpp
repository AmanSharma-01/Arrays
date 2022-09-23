class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low=0, high=0;
        int product=1;
        int ans=0;
        
        while(high < nums.size()) {
            product *= nums[high];
            
            while(product >= k && low<=high) {
                product /= nums[low];
                low++;
            }
            ans += high-low+1;
            high++;
        }
        return ans;
    }
};