class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp;
        dp.push_back({1});
        
        for(int i=1;i<=n;i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++) {
                int a = dp[i-1][j]+dp[i-1][j-1];
                temp.push_back(a);
            }
            temp.push_back(1);
            dp.push_back(temp);
        }
        return dp[n];
    }
};