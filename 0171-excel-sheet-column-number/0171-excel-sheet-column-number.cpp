class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(auto ch: columnTitle) {
            int x = ch-'A'+1;
            ans = 26*ans + x;
        }
        return ans;
    }
};