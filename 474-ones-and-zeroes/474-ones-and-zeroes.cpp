class Solution {
public:
    
    int dp[601][101][101] = {};
    
    int recour(vector<string>& strs, int pos, int m, int n) {
        if(pos >= strs.size()) return 0;
        if(dp[pos][m][n] != -1) return dp[pos][m][n];
        int ans = recour(strs, pos+1, m, n);
        int zcount=0, ocount=0;
        for(int i=0;i<strs[pos].size();i++) {
            if(strs[pos][i] == '0') zcount++;
            else ocount++;
        }
        int answ = 0;
        if(zcount <= m && ocount <= n) answ = 1+recour(strs, pos+1, m-zcount, n-ocount);
        return dp[pos][m][n] = max(ans,answ);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return recour(strs, 0, m, n);
    }
};