class Solution {
public:
    vector<string> ans;
    
    void getP(int n, int currOpen, int currClose, string curr) {
        if(currOpen == n && currClose == n) {
            ans.push_back(curr);
            return;
        }
        
        if(currOpen < n) {
            getP(n, currOpen+1, currClose, curr+'(');
        }
        
        if(currClose < currOpen) {
            getP(n, currOpen, currClose+1, curr+')');
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        getP(n, 0, 0, "");
        return ans;
    }
};