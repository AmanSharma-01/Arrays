class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        
        for(auto ch: s) c^=ch;
        for(auto ch: t) c^=ch;        
        
        return c;
        
//         vector<int> tfreq(26, 0);
//         vector<int> sfreq(26, 0);
        
//         for(auto ch: s) sfreq[ch-'a']++;
//         for(auto ch: t) tfreq[ch-'a']++;
        
//         for(int i=0;i<26;i++) {
//             if(tfreq[i]-sfreq[i] == 1) return 'a'+i;
//         }
        
//         return 'a';
    }
};