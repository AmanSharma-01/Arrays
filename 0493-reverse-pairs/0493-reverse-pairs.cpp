class Solution {
public:
    
    void mergeSort(vector<int>& nums, int st, int ed, int &ans) {
        if(st>=ed) return;
        int mid = st+(ed-st)/2;
        
        mergeSort(nums, st, mid, ans);
        mergeSort(nums, mid+1, ed, ans);
        
        int j = mid+1;
        for(int i=st;i<=mid;i++) {
            while(j<=ed && nums[i] > 2LL*nums[j]) j++;
            ans += j-(mid+1);
        }
        inplace_merge(nums.begin()+st, nums.begin()+mid+1, nums.begin()+ed+1);
    }
    
    int reversePairs(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        mergeSort(nums, 0, n-1, ans);
        return ans;
    }
};