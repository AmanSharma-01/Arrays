class Solution {
private:
    void recur(int n, int open, int close, vector<string>& ans, string curr) {
        if(open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        if(open < n) {
            recur(n, open+1, close, ans, curr+'(');
        }
        if(close < open) {
            recur(n, open, close+1, ans, curr+')');
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        int open=0, close=0;
        vector<string> ans;
        recur(n, open, close, ans, "");
        return ans;
    }
};