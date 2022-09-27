class Solution {
public:
    
    int maxFreq(vector<int>& freq) {
        int ans=0;
        for(int i=0;i<26;i++) {
            ans = max(ans, freq[i]);
        }
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int low=0, high=0, len=0, n=s.length();
        
        while(high < n) {
            freq[s[high]-'A']++;
            
            while((high-low+1) - maxFreq(freq) > k) {
                freq[s[low]-'A']--;
                low++;
            }
            len = max(len, high-low+1);
            high++;
        }
        
        return len;
    }
};