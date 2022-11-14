class Solution {
private:
    int mod = (int)1e9+7;
    int findGoodString(int low, int high, int zero, int one, int idx, vector<long long>& dp) {
        int ans=0;
        if(idx > high) return 0;
        if(dp[idx] != -1) return dp[idx];
        if((idx >= low) && (idx <= high)) ans=1;
        ans = ans + findGoodString(low, high, zero, one, idx+zero, dp) + findGoodString(low, high, zero, one, idx+one, dp);
        return dp[idx] = ans%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<long long> dp(1e5+1,-1);
        ans = findGoodString(low, high, zero, one, 0, dp);
        return ans%mod;
    }
};