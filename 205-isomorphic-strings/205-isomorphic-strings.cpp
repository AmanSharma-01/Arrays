class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        vector<bool> vis(256, false);
        int ss = s.size();
        
        for(int i=0;i<ss;i++) {
            if(mp.find(s[i]) != mp.end()) {
                if(mp[s[i]] != t[i]) return false;
            } else {
                if(vis[t[i]]) return false;
                else {
                    mp[s[i]] = t[i];
                    vis[t[i]] = true;
                }
            }
        }
        
        return true;
    }
};