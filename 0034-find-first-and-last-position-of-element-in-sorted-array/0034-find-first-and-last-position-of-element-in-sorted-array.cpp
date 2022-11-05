class Solution {
private:
    int findLeft(vector<int>& nums, int tar) {
        int n = nums.size();
        int l=0,r=n-1;
        int ans=-1;
        
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid]==tar) {
                ans = mid;
                r=mid-1;
            } else if(nums[mid] < tar) {
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return ans;
    }
    int findRight(vector<int>& nums, int tar) {
        int n = nums.size();
        int l=0,r=n-1;
        int ans=-1;
        
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid]==tar) {
                ans = mid;
                l=mid+1;
            } else if(nums[mid] < tar) {
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1;
        int right = -1;
        
        left = findLeft(nums, target);
        right = findRight(nums, target);
        
        return {left, right};
    }
};