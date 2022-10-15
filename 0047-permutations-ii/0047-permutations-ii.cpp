class Solution {
public:
    vector<vector<int>> ans;
    
    void getPer(vector<int>& nums, int idx) {
        if(idx >= nums.size()) {
            ans.push_back(nums);
            return;
        } 
        
        for(int i=idx;i<nums.size();i++) {
            if(i > idx && nums[idx]==nums[i]) continue;
            swap(nums[i], nums[idx]);
            getPer(nums, idx+1);
        }
        
        for(int i=nums.size()-1;i>idx;i--) {
            swap(nums[i], nums[idx]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        getPer(nums, 0);
        return ans;
    }
};