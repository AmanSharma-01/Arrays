class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int tar = *max_element(nums.begin(), nums.end());
        int len=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==tar) {
                int j=i;
                while(j<n && nums[j]==tar) {
                    j++;
                }
                len = max(len, j-i);
                i=j;
            }
        }
        
        return len;
    }
};