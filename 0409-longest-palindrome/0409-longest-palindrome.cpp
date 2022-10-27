class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int ans=0;
        bool isOddPresent = false;
        
        for(auto ch: s) mp[ch]++;
        
        
        for(auto i: mp) {
            if(i.second%2 == 0) ans+=i.second;
            else {
                if(!isOddPresent) isOddPresent = true;
                int temp = i.second/2;
                ans += temp*2;
            }
        }
        
        if(isOddPresent) return ans+1;
        return ans;
    }
};