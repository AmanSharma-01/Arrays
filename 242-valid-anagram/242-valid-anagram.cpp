class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sfreq(26, 0);
        vector<int> tfreq(26, 0);
        
        for(auto ch: s) sfreq[ch-'a']++;
        for(auto ch: t) tfreq[ch-'a']++;
        
        return sfreq == tfreq;
    }
};