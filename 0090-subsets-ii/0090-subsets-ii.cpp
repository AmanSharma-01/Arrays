class Solution {
public:
    vector<vector<int>> ans;
    
    void getSub(vector<int>& nums, int idx, vector<int>& curr) {
        ans.push_back(curr);
        for(int i=idx;i<nums.size();i++) {
            if(i == idx || nums[i]!=nums[i-1])  {
                curr.push_back(nums[i]);
                getSub(nums, i+1, curr);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        getSub(nums, 0, curr);
        return ans;
    }
};