class Solution {
private:
    void getPermutations(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++) {
            swap(nums[i], nums[idx]);
            getPermutations(nums, idx+1, ans);
            swap(nums[i], nums[idx]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums, 0, ans);
        return ans;
    }
};