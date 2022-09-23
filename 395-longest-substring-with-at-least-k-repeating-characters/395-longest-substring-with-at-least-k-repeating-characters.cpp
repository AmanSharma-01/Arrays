class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k>s.size()) return 0;
        unordered_map<char, int> mp;
        
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }
        
        int left = 0;
        
        while(left < s.size() && mp[s[left]] >= k) left++;
        if(left >= s.size()) return s.size();
        
        int ls = longestSubstring(s.substr(0, left), k);
        
        while(left<s.size() && mp[s[left]] < k) left++;
        
        int rs = longestSubstring(s.substr(left, s.size()), k);
        
        return max(ls, rs);
         
    }
};