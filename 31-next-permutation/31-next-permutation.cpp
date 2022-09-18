class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ptr=n-2, i = n-1;
        
        for(ptr;ptr>=0;ptr--) {
            if(nums[ptr]<nums[ptr+1]) break;
        }
        if(ptr < 0) return reverse(nums.begin(), nums.end());
        
        
        for(i;i>ptr;i--) {
            if(nums[i]>nums[ptr]) break;
        }
        
        swap(nums[ptr], nums[i]);
        return reverse(nums.begin()+ptr+1, nums.end());
    }
};