class Solution {
public:
    
    int recur(vector<int>& days, vector<int>& costs, int idx, vector<int>& dp) {
        int n = days.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int day = costs[0] + recur(days, costs, idx+1, dp);
        int i;
        for(i=idx;i<n && days[i] < days[idx]+7; i++);
        int week = costs[1] + recur(days, costs, i, dp);
        
        for(i=idx;i<n && days[i] < days[idx]+30; i++);
        int month = costs[2] + recur(days, costs, i, dp);
        
        return dp[idx] = min({day, week, month});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(365, -1);
        return recur(days, costs, 0, dp);
    }
};