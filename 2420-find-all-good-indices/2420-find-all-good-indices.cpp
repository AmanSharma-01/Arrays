class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dec(n, 1), inc(n, 1);
        vector<int> ans;
        
        for(int i=1;i<n;i++) {
            if(nums[i-1]>=nums[i]) {
                dec[i] = 1 + dec[i-1];
            }
        }
        
        for(int j=n-2;j;j--) {
            if(nums[j+1]>=nums[j]) {
                inc[j] = 1 + inc[j+1];
            }
        }
        
        for(int i=k;i<n-k;i++) {
            if(dec[i-1]>=k && inc[i+1]>=k) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};