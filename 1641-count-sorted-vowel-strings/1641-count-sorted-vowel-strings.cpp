class Solution {
public:
    vector<char> strs = {'a', 'e', 'i', 'o', 'u'};
    
    int count(int len, char lastChar) {
        if(len == 0) return 1;
        int temp = 0;
        
        for(auto ch: strs) {
            if(ch >= lastChar) {
                temp += count(len-1, ch);
            }
        }
        
        return temp;
    }
    
    int countVowelStrings(int n) {
        int ans=0;
        for(auto ch: strs)
            ans += count(n-1, ch);
        return ans;
    }
};