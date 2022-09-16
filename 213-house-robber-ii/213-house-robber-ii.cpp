class Solution {
public:
    
    int myRob(vector<int>& nums) {
        int take=0,takei=0,skip=0,skipi=0;
        for(int i=0;i<nums.size();i++) {
            takei = nums[i]+skip;
            skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int temp = nums[0];
        nums[0]=0;
        int ans1 = myRob(nums);
        nums[0]=temp;
        nums[n-1]=0;
        int ans2 = myRob(nums);
        
        return max(ans1, ans2);
    }
};