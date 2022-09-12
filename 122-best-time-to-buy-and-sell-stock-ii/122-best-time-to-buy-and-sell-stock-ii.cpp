class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]-prices[i-1] > 0) {
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
        // int profit=0;
        // int buy=INT_MIN;
        // for(int i=0;i<prices.size();i++) {
        //     buy = max(buy, profit-prices[i]);
        //     profit = max(profit, buy+prices[i]);
        // }
        // return profit;
    }
};