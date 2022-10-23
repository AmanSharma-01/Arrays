class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[high]) {
                high = mid;
            } else if(nums[high] == nums[mid]) {
                high--;
            } else {
                low = mid+1;
            }
        }
        
        return nums[low];
        // for (auto n: nums) if (n < nums[0]) return n;
        // return nums[0];
    }
};