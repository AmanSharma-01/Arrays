class Solution {
public:
    bool isValid(unordered_map<char, int>& sfreq, unordered_map<char, int>& tfreq) {
        for(auto i: tfreq) {
            if(i.second > sfreq[i.first]) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char, int> tfreq;
        unordered_map<char, int> sfreq;
        int len=INT_MAX, st=0;
        for(auto ch: t) tfreq[ch]++;
        
        int low=0,high=0;
        
        while(high < s.length()) 
        {
            sfreq[s[high]]++;
            while(isValid(sfreq, tfreq)) {
                if(high-low < len) {
                    st=low;
                    len = high-low+1;
                }
                sfreq[s[low]]--;
                low++;
            }
            high++;
        }
        return len == INT_MAX ? "" : s.substr(st, len);
    }
};