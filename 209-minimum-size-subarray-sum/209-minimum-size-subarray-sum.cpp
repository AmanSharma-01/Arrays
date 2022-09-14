class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int n = nums.size();
        int sum=0;
        int low=0,high=0;
        
        while(high < n) {
            sum+=nums[high++];
            while(sum >= target) {
                sum-=nums[low];
                low++;
                len = min(len, high-low+1);
            }
        }
        return len == INT_MAX ? 0 : len;
        
        // for(int i=0;i<n;i++) {
        //     int sum=0;
        //     for(int j=i;j<n;j++) {
        //         sum += nums[j];
        //         if(sum >= target) {
        //             len = min(len, j-i+1);
        //         }
        //     }
        // }
        // return len == INT_MAX ? 0 : len;
    }
};