class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto num: nums) q.push(num);
        k--;
        while(k--) q.pop();
        return q.top();
    }
};