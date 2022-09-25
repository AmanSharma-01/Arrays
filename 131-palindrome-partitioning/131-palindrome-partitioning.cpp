class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    
    bool isPal(string s) {
        for(int i=0;i<s.size();i++) if(s[i] != s[s.size()-1-i]) return false;
        return true;
    }
    
    void recur(string& s, int beg) {
        if(beg>=s.length()) {
            ans.push_back(curr);
            return;
        }
        
        string c = "";
        for(int i=beg;i<s.size();i++) {
            c += s[i];
            if(isPal(c)) {
                curr.push_back(c);
                recur(s, i+1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        recur(s, 0);
        return ans;
    }
};