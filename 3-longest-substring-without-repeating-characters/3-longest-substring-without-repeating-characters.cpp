class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int n = s.length();
        int low=0,high=0;
        int maxLen=0;
        
        while(high<n) {
            freq[s[high]]++;
            while(freq[s[high]] > 1) {
                freq[s[low]]--;
                low++;
            }
            high++;
            maxLen = max(maxLen, high-low);
        }
        return maxLen;
    }
};