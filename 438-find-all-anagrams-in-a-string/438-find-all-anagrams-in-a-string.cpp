class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pfreq(26, 0);
        vector<int> sfreq(26, 0);
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        int high=0, low=0;
        while(high < p.size()) {
            pfreq[p[high]-'a']++;
            sfreq[s[high++]-'a']++;
        }
        high--;
        while(high<s.size()) {
            if(pfreq == sfreq) {
                ans.push_back(low);
            }
            high++;
            if(high < s.size()) {
                sfreq[s[high]-'a']++;
            }
            sfreq[s[low]-'a']--;
            low++;
        }
        return ans;
    }
};