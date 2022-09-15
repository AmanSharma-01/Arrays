class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans=INT_MAX, close=INT_MAX;
        
        for(int i=0;i<n;i++) {
            int low=i+1, high=n-1;
            
            while(low<high) {
                int currSum = nums[i]+nums[low]+nums[high];
                if(currSum==target) return target;
                
                if(abs(currSum-target)<close) {
                    ans = currSum;
                    close = abs(currSum-target);
                }
                
                
                else if(currSum < target) low++;
                else high--;
            }
        }
        return ans;
    }
};