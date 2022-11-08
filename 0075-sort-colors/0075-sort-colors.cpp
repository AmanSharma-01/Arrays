class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int st=0,ed=n-1;
        int curr=0;
        
        while(curr<=ed) {
            if(nums[curr]==0) {
                swap(nums[curr], nums[st]);
                curr++;
                st++;
            }
            else if(nums[curr]==2) {
                swap(nums[curr], nums[ed]);
                ed--;
            } else {
                curr++;
            }
        }
    }
};