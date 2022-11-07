class Solution {
private:
    vector<vector<char>> mp={{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    void getStrings(string dig, int idx, string curr, vector<string>& ans) {
        if(idx == dig.size()) {
            if(curr.size() != 0) ans.push_back(curr);
            return;
        }
        
        for(auto ch: mp[dig[idx]-'0']) {
            getStrings(dig, idx+1, curr+ch, ans);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        getStrings(digits, 0, "", ans);
        return ans;
    }
};