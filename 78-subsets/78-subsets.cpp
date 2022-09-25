class Solution {
public:
    vector<vector<int>> ans;
    
    void recur(vector<int>& nums, int beg, vector<int> curr) {
        if(beg >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        recur(nums, beg+1, curr);
        curr.push_back(nums[beg]);
        recur(nums, beg+1, curr);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        recur(nums, 0, curr);
        return ans;
    }
};