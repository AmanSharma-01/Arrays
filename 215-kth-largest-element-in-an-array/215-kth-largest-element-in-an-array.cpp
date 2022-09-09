class Solution {
public:
    
    int partition(vector<int> &nums, int st, int ed, int selectedPivot) {
        int p=st;
        for(int i=st;i<=ed-1;i++) {
            if(nums[i] <= selectedPivot) {
                swap(nums[p], nums[i]);
                p++;
            }
        }
        swap(nums[p], nums[ed]);
        return p;
    }
    
    int quickSelect(vector<int>& nums, int st, int ed, int targetIndex) {
        int pivot = partition(nums, st, ed, nums[ed]); // nums[ed] is the selected pivot.
        if(pivot == targetIndex) return nums[pivot];
        else if(pivot < targetIndex) return quickSelect(nums, pivot+1, ed, targetIndex);
        return quickSelect(nums, st, pivot-1, targetIndex);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, n-k);
    }
};