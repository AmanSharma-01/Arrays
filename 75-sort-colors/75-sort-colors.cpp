class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int st=0, ed=n-1;
        int i=0;
        while(i<=ed) {
            if(nums[i]==0) {
                swap(nums[i], nums[st]);
                st++;
                i++;
            } else if(nums[i]==2) {
                swap(nums[i], nums[ed]);
                ed--;
            } else {
                i++;
            }
        }
    }
};