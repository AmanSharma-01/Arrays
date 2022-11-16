class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> pfreq(26, 0);
        vector<int> sfreq(26, 0);
        int high=0, low=0;
        int n = p.size();
        int m = s.size();
        
        if(n > m) return {};
        
        while(high < n) {
            pfreq[p[high]-'a']++;
            sfreq[s[high++]-'a']++;
        }
        high--;
        while(high < m) {
            if(sfreq == pfreq) {
                ans.push_back(low);
            }
            high++;
            if(high < m) {
                sfreq[s[high]-'a']++;
            }
            sfreq[s[low]-'a']--;
            low++;
        }
        
        return ans;
    }
};