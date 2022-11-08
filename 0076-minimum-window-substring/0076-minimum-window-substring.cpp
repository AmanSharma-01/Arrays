class Solution {
private:
    bool isValid(unordered_map<char, int>& sfreq, unordered_map<char, int>& tfreq) {
        for(auto ch: tfreq) {
            if(ch.second > sfreq[ch.first]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sfreq;
        unordered_map<char, int> tfreq;
        
        for(auto ch: t) tfreq[ch]++;
        
        int low=0,high=0;
        int st=-1, len = INT_MAX;
        
        while(high<s.size()) {
            sfreq[s[high++]]++;
            while(isValid(sfreq, tfreq) && low<high) {
                if(len > high-low) {
                    st = low;
                    len = high-low;
                }
                sfreq[s[low]]--;
                low++;
            }
        }
        
        return len == INT_MAX ? "" : s.substr(st, len);
    }
};