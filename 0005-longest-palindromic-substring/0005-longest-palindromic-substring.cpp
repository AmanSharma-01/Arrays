class Solution {
private: 
    int expand(string& s, int st, int ed) {
        while(st>=0 && ed<s.size() && s[st]==s[ed])st--,ed++;
        return ed-st-1;
    }
public:
    string longestPalindrome(string s) {
        int len=0, start=0;
        
        for(int i=0;i<s.size();i++) {
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i+1);
            if(max(l1, l2) > len) {
                len = max(l1, l2);
                start = i-(len-1)/2;
            }
        }
        
        return s.substr(start, len);
    }
};