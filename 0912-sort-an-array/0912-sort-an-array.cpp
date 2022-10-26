class Solution {
public:
    
    void mergeSort(vector<int>& nums, int st, int ed) {
        if(st>=ed) return;
        int mid = st + (ed-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, ed);
        inplace_merge(nums.begin()+st, nums.begin()+mid+1, nums.begin()+ed+1);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};