class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit1=0,profit2=0, buy1=INT_MIN, buy2=INT_MIN;
        for(int i=0;i<n;i++) {
            buy1 = max(buy1, -prices[i]);
            profit1 = max(profit1, buy1+prices[i]);
            buy2 = max(buy2, profit1-prices[i]);
            profit2 = max(profit2, buy2+prices[i]);
        }
        return profit2;
    }
};