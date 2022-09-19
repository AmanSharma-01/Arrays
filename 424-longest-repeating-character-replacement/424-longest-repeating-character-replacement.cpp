class Solution {
public:
    
    int findMax(vector<int>& maxFreq) {
        int ans = 0;
        for(int i=0;i<26;i++) {
            ans = max(ans, maxFreq[i]);
        }
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        vector<int> maxFreq(26, 0);
        int n = s.length();
        int low=0,high=0;
        int ans = 0;
        
        while(high < n) {
            maxFreq[s[high]-'A']++;
            while((high-low+1)-findMax(maxFreq) > k) {
                maxFreq[s[low]-'A']--;
                low++;
            }
            ans = max(ans, high-low+1);
            high++;
        }
        return ans;
    }
};