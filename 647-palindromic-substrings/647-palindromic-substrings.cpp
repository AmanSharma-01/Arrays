class Solution {
public:
    
    int expand(string& s, int st, int ed) {
        while(st>=0 && ed<s.size() && s[st]==s[ed]) st--, ed++;
        return ed-st-1;
    }
    
    int countSubstrings(string s) {
        int ans=0;
        int n = s.length();
        
        for(int i=0;i<n;i++) {
            int l1 = expand(s, i, i);
            ans += (l1+1)/2;
            int l2 = expand(s, i, i+1);
            ans += (l2)/2;
        }
        return ans;
    }
};