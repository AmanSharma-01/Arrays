class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p1, p2;
        for(p1=n-2;p1>=0;p1--) {
            if(nums[p1] < nums[p1+1]) break;
        }
        if(p1<0) return reverse(nums.begin(), nums.end());
        for(p2=n-1;p2>p1;p2--) {
            if(nums[p2]>nums[p1]) break;
        }
        swap(nums[p1], nums[p2]);
        reverse(nums.begin()+p1+1, nums.end());
    }
};