class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string snew = "";
        
        for(int i=0;i<s.size();i++) {
            if(s[i] == '#') {
                if(snew.size()>0) snew.pop_back();
            } else {
                snew += s[i];
            }
        }
        
        string tnew = "";
        
        for(int i=0;i<t.size();i++) {
            if(t[i] == '#') {
                if(tnew.size()>0) tnew.pop_back();
            } else {
                tnew += t[i];
            }
        }
        
        return snew == tnew;
    }
};