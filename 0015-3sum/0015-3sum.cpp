class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j=i+1, k=n-1;
            
            while(j<k) {
                if(nums[i]+nums[j]+nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int temp = nums[j];
                    while(j<k && temp == nums[j])j++;
                    temp = nums[k];
                    while(j<k && temp == nums[k])k--;
                }
                else if(nums[i]+nums[j]+nums[k] < 0) j++;
                else k--;
            }
        }
        
        return ans;
    }
};