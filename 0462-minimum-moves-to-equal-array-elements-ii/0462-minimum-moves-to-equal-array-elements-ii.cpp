class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tar = (n-1)/2;
        int ans=0;
        
        int val = nums[tar];
        
        for(int i=0;i<n;i++) {
            ans += abs(nums[i]-nums[tar]);
        }
        
        return ans;
    }
};