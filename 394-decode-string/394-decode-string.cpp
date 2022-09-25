class Solution {
public:
    
    string decode(string& s, int& pos) {
        if(pos >= s.length()) return "";
        string ans = "";
        
        while(pos<s.length() && s[pos] != ']') {
            if(isdigit(s[pos])) {
                int num=0;
                int j=pos;
                for(;j<s.length()&&isdigit(s[j]);j++) {
                    num = num*10+(s[j]-'0');
                }
                pos=j+1;
                string t = decode(s,pos);
                for(int k=0;k<num;k++) {
                    ans += t;
                }
            }
            else {
                ans+=s[pos];
            }
            pos++;
        } 
        return ans;
    }
    
    string decodeString(string s) {
        int pos=0;
        return decode(s, pos);
    }
};