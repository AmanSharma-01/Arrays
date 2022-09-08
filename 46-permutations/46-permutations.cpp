class Solution {
public:
    vector<vector<int>> ans;
    
    void getP(vector<int>&nums, int beg) {
        if(beg >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=beg;i<nums.size();i++) {
            swap(nums[beg], nums[i]);
            getP(nums, beg+1);
            swap(nums[beg], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        getP(nums, 0);
        return ans;
    }
};