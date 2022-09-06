class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, buy=INT_MIN;
        for(int i=0;i<prices.size();i++) {
            buy = max(buy, -prices[i]);
            profit = max(profit, buy+prices[i]);
        }
        return profit;
    }
};