class Solution {
public:
    
    void cap(string s, int idx, vector<string>& ans) {
        if(idx == s.size()) {
            ans.push_back(s);
            return;
        }
        
        char ch = s[idx];
        s[idx] = islower(ch) ? toupper(ch) : tolower(ch);
        cap(s, idx+1, ans);
        
        if(isalpha(ch)) {
            s[idx] = ch;
            cap(s, idx+1, ans);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        cap(s, 0, ans);
        return ans;
    }
};