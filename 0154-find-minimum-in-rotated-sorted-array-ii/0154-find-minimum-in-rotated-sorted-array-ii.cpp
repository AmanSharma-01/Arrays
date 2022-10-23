class Solution {
public:
    int findMin(vector<int>& nums) {
        for (auto n: nums) if (n < nums[0]) return n;
        return nums[0];
    }
};