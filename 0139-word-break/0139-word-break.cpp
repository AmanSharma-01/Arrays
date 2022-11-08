class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        
        for(int i=0;i<n;i++) {
            for(int j=i;j>=0;j--) {
                string temp = s.substr(j, i-j+1);
                if(st.find(temp) != st.end()) {
                    dp[i+1] = dp[j]||dp[i+1];
                }
            }
        }
        
        return dp[n];
    }
};