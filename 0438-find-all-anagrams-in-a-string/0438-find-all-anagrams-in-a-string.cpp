class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sfreq(26, 0), pfreq(26, 0), ans;
        int ss=s.size(), ps=p.size();
        if(ps > ss) return {};
        
        int low=0, high=0;
        while(high < ps) {
            pfreq[p[high]-'a']++;
            sfreq[s[high++]-'a']++;
        }
        
        high--;
        
        while(high < ss) {
            if(sfreq == pfreq) {
                ans.push_back(low);
            }
            
            high++;
            if(high < ss) {
                sfreq[s[high]-'a']++;
            }
            
            sfreq[s[low]-'a']--;
            low++;
        }
        
        return ans;
    }
};