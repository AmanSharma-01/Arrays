class Solution {
public:
    bool recur(vector<int>& nums, int sum1, int sum2, bool canPlay, int st, int ed) {
        if(st>ed) {
            return sum1 >= sum2;
        }
        if(canPlay) {
            // player 1 turn.
            return recur(nums, sum1+nums[st], sum2, !canPlay, st+1, ed) || recur(nums, sum1+nums[ed], sum2, !canPlay, st, ed-1);
        } else {
            // player 2 turn.
            return recur(nums, sum1, sum2+nums[st], !canPlay, st+1, ed) && recur(nums, sum1, sum2+nums[ed], !canPlay, st, ed-1);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum1=0;
        int sum2=0;
        bool canPlay=true;
        return recur(nums, sum1, sum2, canPlay, 0, n-1);
    }
};