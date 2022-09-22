class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;
        string shash = "";
        string thash = "";
        
        for(int i=0;i<s.size();i++) {
            if(smp.find(s[i]) == smp.end()) {
                shash += to_string(i)+',';
                smp[s[i]] = i;
            } else {
                shash += to_string(smp[s[i]])+',';
            }
        }
        
        for(int i=0;i<t.size();i++) {
            if(tmp.find(t[i]) == tmp.end()) {
                thash += to_string(i)+',';
                tmp[t[i]] = i;
            } else {
                thash += to_string(tmp[t[i]])+',';
            }
        }
        
        return shash == thash;
    }
};