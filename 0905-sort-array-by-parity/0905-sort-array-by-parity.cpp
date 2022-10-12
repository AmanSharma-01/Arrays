class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1;
        int curr=0;
        
        while(s<=e) {
            if(nums[curr]%2) {
                swap(nums[s], nums[e]);
                e--;
            } else {
                s++;
                curr++;
            }
        }
        
        return nums;
    }
};