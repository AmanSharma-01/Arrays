class Solution {
public:
    
    int expand(string& s, int st, int ed) {
        while(st>=0 && ed<s.length() && s[st] == s[ed]) st--,ed++;
        return ed-st-1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int len=0;
        int start=0;
        
        for(int i=0;i<n;i++) {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i+1);
            
            if(max(l1,l2) > len) {
                len = max(l1,l2);
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, len);
    }
};