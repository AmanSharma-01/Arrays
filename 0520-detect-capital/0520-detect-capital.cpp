class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cap = 0;
        
        for(int i=0;i<n;i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                cap++;
            }
        }
        
        if(cap == n) return true;
        if(cap == 1 && (word[0] >= 'A' && word[0] <= 'Z')) return true;
        if(cap == 0) return true;
        return false;
    }
};