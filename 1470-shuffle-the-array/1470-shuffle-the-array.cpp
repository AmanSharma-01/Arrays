class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0, j=n;
        int curr=0;
        vector<int> ans(2*n, -1);
        
        while(i<n && j<2*n) {
            ans[curr++] = nums[i++];
            ans[curr++] = nums[j++];
        }
        
        return ans;
    }
};